// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/9/18
// Class: CS 172

#include "Ecosystem.h"

//constructs an ecosystem object with no species
Ecosystem::Ecosystem()
{
  //to increase the values of these data fields objects must be added
  //to the allSpecies vector
  numberSpecies = 0;
  numberIndependentSpecies = 0;
  numberPredatorPrey = 0;
}

//accessor function for numberSpecies
int Ecosystem::getNumberSpecies() const
{
  return numberSpecies;
}

//accessor function for numberIndependentSpecies
int Ecosystem::getNumberIndependentSpecies() const
{
  return numberIndependentSpecies;
}

int Ecosystem::getNumberPredatorPrey() const
{
  return numberPredatorPrey;
}

//accessor function for allSpecies vector
vector <Species*> Ecosystem::getAllSpecies() const
{
  return allSpecies;
}

//adds a species object to the vector
void Ecosystem::addSpecies( const Species& species)
{
  //uses the copy constructor
  allSpecies.push_back(new Species (species));
  numberSpecies++;
}

// adds an independentspecies object to the vector
void Ecosystem::addIndependentSpecies(const IndependentSpecies&
  independentSpecies)
{

  allSpecies.push_back(new IndependentSpecies (independentSpecies));
  numberIndependentSpecies++;
  numberSpecies++;
}

//adds a predatorprey object to the vector
void Ecosystem::addPredatorPrey( const PredatorPrey& predatorPrey)
{
  allSpecies.push_back(new PredatorPrey (predatorPrey));
  numberPredatorPrey++;
  numberSpecies++;
}