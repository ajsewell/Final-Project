// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/9/18
// Class: CS 172

#ifndef INDEPENDENTSPECIES_H_
#define INDEPENDENTSPECIES_H_
#include "Species.h"

class IndependentSpecies: public Species
{
public:
  IndependentSpecies();
  IndependentSpecies(string name, double size, double time, double
  growthRate, double carryingCapacity, double pAlleleFrequency);
  IndependentSpecies(string name, double size, double time, double
  growthRate, double carryingCapacity);
  IndependentSpecies(const IndependentSpecies&);
  double getTime() const;
  void setTime(double time);
  double getGrowthRate() const;
  double getCarryingCapacity() const;
  double calculatePopulationSize();
private:
  double time; //time is in years
  double growthRate;
  double carryingCapacity;

};

#endif