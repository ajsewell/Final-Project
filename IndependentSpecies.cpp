// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/9/18
// Class: CS 172

#include "IndependentSpecies.h"
#include <cmath>

//constructs an independentspecies object with default values
IndependentSpecies::IndependentSpecies()
{
  time = 0;
  growthRate = 0.5;
  carryingCapacity = 5000;
}

//constructs an independentspecies object with specified values for name,
//size, time,  growthRate, carryingCapacity, pAlleleFrequency, and
//qAlleleFrequency
IndependentSpecies::IndependentSpecies(string name, double size, double
  time, double growthRate, double carryingCapacity, double pAlleleFrequency)
{
  this->name = name;
  this->size = size;
  this->time = time;
  this->growthRate = growthRate;
  this->carryingCapacity = carryingCapacity;
  this->pAlleleFrequency = pAlleleFrequency;
}

//constructs an independentspecies object with specified values for name,
//size, time,  growthRate, and carryingCapacity
IndependentSpecies::IndependentSpecies(string name, double size, double
  time, double growthRate, double carryingCapacity)
{
  this->name = name;
  this->size = size;
  this->time = time;
  this->growthRate = growthRate;
  this->carryingCapacity = carryingCapacity;
}

//copy constructor
IndependentSpecies::IndependentSpecies(const IndependentSpecies& species)
{
  name = species.name;
  size = species.size;
  time = species.time;
  growthRate = species.growthRate;
  carryingCapacity = species.carryingCapacity;
  pAlleleFrequency = species.pAlleleFrequency;
}

//accessor function for time
double IndependentSpecies::getTime() const
{
  return time;
}

//mutator function for time
void IndependentSpecies::setTime(double time) 
{
  this->time = time;
}

//accessor function for growthRate
double IndependentSpecies::getGrowthRate() const
{
  return growthRate;
}

//accessor function for carryingCapacity
double IndependentSpecies::getCarryingCapacity() const
{
  return carryingCapacity;
}

//the following calculation is based on the logistic equation
//information on this equation was found in section 2.5 of 
//Elementary Differential Equations by Boyce and diPrima

//calculates and returns the population size at a specified time
double IndependentSpecies::calculatePopulationSize()
{
  double newSize = (size * carryingCapacity) / (size +
  (carryingCapacity - size) * pow(2.7183, -(growthRate * time)));
  size = (static_cast<int>(newSize));
  return size;
}