// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/9/18
// Class: CS 172

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Ecosystem.h"
#include "Species.h"
#include "IndependentSpecies.h"
#include "PredatorPrey.h"
using namespace std;

//displays the genetic makeup of a population in a file
void printStats(Ecosystem& ecosystem, fstream& output)
{
  vector<Species*> allSpecies = ecosystem.getAllSpecies();
  for (int i = 0; i < allSpecies.size(); i++)
  {
    output << "Proportion homozygous dominant for " <<
    allSpecies[i]->getName() << ": " <<
    allSpecies[i]->findHomozygousDominant() << endl;
    output << "Proportion heterozygous for " << allSpecies[i]->getName() <<
    ": " << allSpecies[i]->findHeterozygous() << endl;
    output << "Proportion homozygous recessive for " <<
    allSpecies[i]->getName() << ": " <<
    allSpecies[i]->findHomozygousRecessive() << endl;
    output << "Number with dominant phenotype for " <<
    allSpecies[i]->getName() << ": " << allSpecies[i]->findNumberDominant()
    << endl;
    output << "Number with recessive phenotype for " <<
    allSpecies[i]->getName() << ": " << allSpecies[i]->findNumberRecessive()
    << endl;

  }
  output << endl;
}

void displayMinMaxAverage(vector<double> vector, fstream& stream)
{
  double min = vector[0];
  double max = vector[0];
  int maxIndex = 0;
  int minIndex = 0;
  double sum = 0;
  //finds minimum and maximum values and the sum
  for (int i = 0; i < vector.size(); i++)
  {
    if (vector[i] < min)
    {
      min = vector[i];
      minIndex = i;
    }
    if (vector[i] > max)
    {
      max = vector[i];
      maxIndex = i;
    }
    sum += vector[i];
  }
  double average = sum / vector.size();
  stream << "The minimum population size is " << static_cast<int>(min) <<
  " at time " << minIndex << endl;
  stream << "The maximum population size is " << static_cast<int>(max) <<
    " at time " << maxIndex << endl;
  stream << "The average population size is " << average << endl;
}



//displays a table of population size at different times
void printTable(Ecosystem& ecosystem, fstream& output)
{
  vector<Species*> allSpecies = ecosystem.getAllSpecies();
  for (int i = 0; i < allSpecies.size(); i++)
  {
    if (typeid(*allSpecies[i]) == typeid(IndependentSpecies))
    {
      double initialSize = dynamic_cast<IndependentSpecies*>
      (allSpecies[i])-> getSize();
      double time = dynamic_cast<IndependentSpecies*>(allSpecies[i])
      ->getTime();
      vector<double> populations;

      output << "time " <<dynamic_cast<IndependentSpecies*>(allSpecies[i])
      ->getName() << " population size " << endl;
      for (int j = 0; j <= time; j++)
      {
        dynamic_cast<IndependentSpecies*>(allSpecies[i])
        ->setTime(j);
        output << dynamic_cast<IndependentSpecies*>(allSpecies[i])
        ->getTime() << setw(8) <<
        dynamic_cast<IndependentSpecies*>(allSpecies[i])
        ->calculatePopulationSize() << endl;
        populations.push_back(dynamic_cast<IndependentSpecies*>(allSpecies[i])
        ->getSize());
        //resets to the initial size for use in the calculatePopulationSize
        //equation
        dynamic_cast<IndependentSpecies*>(allSpecies[i])
        ->setSize(initialSize);
        }
      output << endl;
      displayMinMaxAverage(populations, output);
    }
  }
}

//prints a table of prey population size and predator population size at
// different times.
void printPredatorPreyTable(Ecosystem& ecosystem, fstream& output)
{
  vector<Species*> allSpecies = ecosystem.getAllSpecies();

  for (int i = 0; i < allSpecies.size(); i++)
  {
    if (typeid (*allSpecies[i]) == typeid (PredatorPrey))
    {
      double initialSize =
      allSpecies[i]->getSize();
      double initialPredatorSize = dynamic_cast<PredatorPrey*>
      (allSpecies[i])->getPredatorSize();
      double time = dynamic_cast<PredatorPrey*>
      (allSpecies[i])->getTime();
      vector<double> preyPopulations;
      vector<double> predatorPopulations;
      output << "time " << 
      allSpecies[i]->getName() << " population size "
      << dynamic_cast<PredatorPrey*>
      (allSpecies[i])->getPredatorName() << " population size"
      << endl;
      for (int j = 0; j <= time; j++)
      {
        dynamic_cast<PredatorPrey*>
        (allSpecies[i])->setTime(j);
        output << dynamic_cast<PredatorPrey*>
        (allSpecies[i])->getTime() << setw(8) <<
        dynamic_cast<PredatorPrey*>
        (allSpecies[i])->calculatePreyPopulation() << setw(21) <<
        dynamic_cast<PredatorPrey*>
        (allSpecies[i])->calculatePredatorPopulation() << endl;
        preyPopulations.push_back(
        allSpecies[i]->getSize());
        predatorPopulations.push_back(dynamic_cast<PredatorPrey*>
        (allSpecies[i])->getPredatorSize());
        allSpecies[i]->setSize(initialSize);
        dynamic_cast<PredatorPrey*>
        (allSpecies[i])->setPredatorSize(initialPredatorSize);
      }
      output << endl;
      output << "For " << allSpecies[i]->getName() << " :" << endl;
      displayMinMaxAverage(preyPopulations, output);
      output << "For " << dynamic_cast<PredatorPrey*>
      (allSpecies[i])->getPredatorName() << " :" << endl;
      displayMinMaxAverage(predatorPopulations, output);
    }
  }
}

//frees memory
void deleteVector(Ecosystem& ecosystem)
{
  for (int i = 0; i < ecosystem.getAllSpecies().size(); i++)
    delete ecosystem.getAllSpecies()[i];
}


int main()
{
  //creates independentspecies and predatorprey objects
  IndependentSpecies robin("robin", 1000, 12, 0.25, 5000, 0.25);
  PredatorPrey rabbit_coyote;

  //adjusts values for predatorprey object
  rabbit_coyote.setPredatorName("coyote");
  rabbit_coyote.setSize(1050);
  rabbit_coyote.setPredatorSize(80);

  //creates an ecosystem object and adds species to it
  Ecosystem myBackyard;
  myBackyard.addIndependentSpecies(robin);
  myBackyard.addPredatorPrey(rabbit_coyote);
  vector<Species*> allSpecies = myBackyard.getAllSpecies();

  fstream output;
  if (output.fail())
  {
    cout << "Could not open file" << endl;
    return -1;
  }
  output.open("Results", ios::out);
  //displays statistics for the species in a file
  printStats(myBackyard, output);
  printTable(myBackyard, output);
  printPredatorPreyTable(myBackyard, output);
  deleteVector(myBackyard);
  output.close();

  string filename, name;
  double size, pAlleleFrequency, time, growthRate, carryingCapacity;

  //opens file with information for independentspecies
  cout << "Enter a file name: " << endl;
  cin >> filename;
  fstream input;
  input.open(filename.c_str(), ios::in);
  if (input.fail())
  {
    cout << "Could not open file" << endl;
    return -1;
  }

  Ecosystem ecosystem;

  //inputs information and creates independentspecies object
  while (!input.eof())
  {
    input >> name >> size >> time >> growthRate >>
    carryingCapacity >> pAlleleFrequency;
    IndependentSpecies species(name, size, time, growthRate,
      carryingCapacity, pAlleleFrequency);
    ecosystem.addIndependentSpecies(species);
  }
  input.close();

  fstream output2;
  string filename2, name2, predatorName;
  double size2, predatorSize, time2,  preyGrowthRate, 
  deathRate, alpha, gamma;

  //opens a file and inputs predatorprey information
  cout << "Enter a predator/prey file: " << endl;
  cin >> filename2;
  fstream input2;
  input2.open(filename2.c_str(), ios::in);
  if (input2.fail())
  {
    cout << "Could not open file" << endl;
    return -1;
  }

  while (!input2.eof())
  { 
    input2 >> name2 >> predatorName >>
    size2 >> predatorSize >> time2 >> preyGrowthRate >>
    deathRate >> alpha >> gamma;
    PredatorPrey species2(name2, predatorName, size2, predatorSize,
      time2, preyGrowthRate, deathRate, alpha, gamma);
    ecosystem.addPredatorPrey(species2);
  }
 

  //displays information in a file
  //can create or append the file
  output2.open("Results2", ios::out | ios::app);
  if (output2.fail())
  {
    cout << "Could not open file" << endl;
    return -1;
  }
  printStats(ecosystem, output2);
  printTable(ecosystem, output2);
  printPredatorPreyTable(ecosystem, output2);
  deleteVector(ecosystem);
  output2.close();

  return 0;
}