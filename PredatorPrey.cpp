// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/8/18
// Class: CS 172

#include "PredatorPrey.h"
#include <cmath>
#include <iostream>

//checks to see if model is valid for the values entered
bool PredatorPrey::isValid() const
{
  if ((abs(size - predatorDeathRate / gamma) <= size * 0.45)
  && (abs(predatorSize - preyGrowthRate / alpha) <=
  predatorSize * 0.45))
    return true;
  else
    return false;
}

//constructs a predatorprey object with default values
PredatorPrey::PredatorPrey()
{
  predatorName = " wolf";
  predatorSize = 100;
  preyGrowthRate = 50.0;
  predatorDeathRate = 500.0;
  time = 12;
  alpha = 0.5; //alpha and gamma represent the level of interaction
  gamma = 0.5; //between predator and prey
}

//constructs a predatorprey object with specified values for name, size,
//time, growthRate, pAlleleFrequency, and qAlleleFrequency
PredatorPrey::PredatorPrey(string name, double size, double time, double
  growthRate, double pAlleleFrequency)
{
    this->name = name;
    predatorName = " wolf";
    this->size = size;
    predatorSize = 100.0;
    this->time = (time >= 0) ? time : 0; //time should not be negative
    preyGrowthRate = growthRate;
    predatorDeathRate = 500.0;
    alpha = 0.5;
    gamma = 0.5;
    this->pAlleleFrequency = pAlleleFrequency;
}

//constructs a predatorprey object with specified values for name,
//predatorName, size, predatorSize, time, preyGrowthRate,
//predatorDeathRate, alpha, and gamma
PredatorPrey::PredatorPrey(string name, string predatorName, double size,
  double predatorSize, double time, double growthRate, double deathRate,
  double alpha, double gamma)
{
  this->name = name;
  this->predatorName = predatorName;
  this->size = size;
  this->predatorSize = (predatorSize >= 0) ? predatorSize : 0;
  this->time = (time >= 0) ? time : 0;
  preyGrowthRate = growthRate;
  predatorDeathRate = deathRate;
  this->alpha = alpha;
  this->gamma = gamma;
}

//copy constructor
PredatorPrey::PredatorPrey(const PredatorPrey& species)
{
  name = species.name;
  predatorName = species.predatorName;
  size = species.size;
  predatorSize = species.predatorSize;
  preyGrowthRate = species.preyGrowthRate;
  predatorDeathRate = species.predatorDeathRate;
  time = species.time;
  alpha = species.alpha;
  gamma = species.gamma;
}

//accessor function for predatorName
string PredatorPrey::getPredatorName() const
{
  return predatorName;
}

//mutator function for predatorName
void PredatorPrey::setPredatorName(string predatorName)
{
  this->predatorName = predatorName;
}

//accessor function for predatorSize
double PredatorPrey::getPredatorSize() const
{
  return predatorSize;
}

//mutator function for predatorSize
void PredatorPrey::setPredatorSize(double predatorSize)
{

  this->predatorSize = (predatorSize >= 0) ? predatorSize : 0;
}

//accessor function for predatorDeathRate
double PredatorPrey::getPredatorDeathRate() const
{
  return predatorDeathRate;
}

//mutator function for predatorDeathRate
void PredatorPrey::setPredatorDeathRate(double deathRate)
{
    predatorDeathRate = deathRate;
}

//accessor function for time
double PredatorPrey::getTime() const
{
  return time;
}

//mutator function for time
void PredatorPrey::setTime(double time)
{
  this->time = time;
}

//accessor function for preyGrowthRate
double PredatorPrey::getPreyGrowthRate() const
{
  return preyGrowthRate;
}

//accessor function for alpha
double PredatorPrey::getAlpha() const
{
  return alpha;
}

//mutator function for alpha
void PredatorPrey::setAlpha(double alpha)
{
    this->alpha = alpha;
}

//accessor function for gamma
double PredatorPrey::getGamma() const
{
  return gamma;
}

//mutator function for gamma
void PredatorPrey::setGamma(double gamma)
{
    this->gamma = gamma;
}

//the following calculations are based on the Lotka-Volterra equations
//information on these equations was found in section 9.5 of 
//Elementary Differential Equations by Boyce and diPrima

//calculates phi to use in equations for finding predator
//and prey populations
double PredatorPrey::findPhi() const
{
  return atan((predatorSize - preyGrowthRate / alpha) / ((preyGrowthRate /
  alpha) * sqrt(predatorDeathRate / preyGrowthRate) * (size *
  gamma / predatorDeathRate - 1)));
}

//calculates K to use in equations for finding predator
//and prey populations
double PredatorPrey::findK() const
{
  return (size * gamma / predatorDeathRate - 1) / cos(findPhi());
}

//gives the size of the prey population at the specified time
//prey and predator populations should show periodic fluctuations
double PredatorPrey::calculatePreyPopulation()
{
  if (isValid()) //checks if values work
  { 
    double newSize = predatorDeathRate / gamma + predatorDeathRate / gamma
    * findK() * cos(sqrt(preyGrowthRate * predatorDeathRate) * time
    + findPhi());
    size = newSize;
    return static_cast<int>(size);
  }
  else
  {
    cout << "invalid values" << endl;
    return 0;
  }
}

//gives the size of the predator population at the specified time
double PredatorPrey::calculatePredatorPopulation()
{
  if (isValid())
  {
    if (getSize() == predatorDeathRate / gamma)
      //this is so the program returns the correct valuea for 
      //this special case
    size = size + 0.01;
    double newSize = preyGrowthRate / alpha + preyGrowthRate / alpha *
    sqrt(predatorDeathRate / preyGrowthRate) * findK() * sin(sqrt
    (preyGrowthRate * predatorDeathRate) * time + findPhi());
    predatorSize = newSize;
    return static_cast<int>(predatorSize);
  }
  else
  {
    cout << "invalid values" << endl;
    return 0;
  }
}

