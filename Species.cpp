// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/8/18
// Class: CS 172

#include "Species.h"

//constructs a species object with default values
Species::Species()
{
  size = 1000.0;
  name = "rabbit";
  pAlleleFrequency = 0.5;
}

//constructs a species object with the specified values
Species::Species(string name, double size, double pAlleleFrequency)
{
  this->name = name;
  this->size = (size >= 0) ? size : 0; 
  //a population size cannot be a negative number
  this->pAlleleFrequency = (pAlleleFrequency >= 0 && pAlleleFrequency <= 
  1) ? pAlleleFrequency: 0;
  //p allele frequency is a  proportion and can't be less than zero
  //or greater than one
}

//copy constructor for species
Species::Species(const Species& species)
{
  name = species.name;
  size = species.size;
  pAlleleFrequency = species.pAlleleFrequency;
}

//accessor function for name
string Species::getName() const
{
  return name;
}

//mutator function for name
void Species::setName(string name)
{
  this->name = name;
}

//accessor function for initialSize
double Species::getSize() const
{
  return size;
}

//mutator function for size
void Species::setSize(double size)
{
  this->size = (size >= 0) ? size : 0;
}

//accessor function for pAlleleFrequency
double Species::getPAlleleFrequency() const
{
  return pAlleleFrequency;
}

//mutator function for pAlleleFrequency
void Species::setPAlleleFrequency(double pAlleleFrequency)
{
  this->pAlleleFrequency = (pAlleleFrequency >= 0 && pAlleleFrequency <=
  1) ? pAlleleFrequency : 0;
}

//calculates qAlleleFrequency. pAlleleFrequency and qAlleleFrequency
//must add up to one
double Species::getQAlleleFrequency() const
{
  return 1 - pAlleleFrequency;
}


//The Hardy-Weinberg equation p^2 + 2pq + q^2 is used in the following 
//functions. Information on this equation was found on pages 398-400
//of Biology by Mason, Losos, and Singer

//returns the percent of individuals in a population that
//exhibit the homoozygous dominant genotype
double Species::findHomozygousDominant() const
{
  return pAlleleFrequency * pAlleleFrequency;
}

//returns the percent of heterozygous individuals in a population
double Species::findHeterozygous() const
{
  return pAlleleFrequency * getQAlleleFrequency() * 2;
}

//returns the percent of homozygous recessive individuals in a population
double Species::findHomozygousRecessive() const
{
  return getQAlleleFrequency() * getQAlleleFrequency();
}

//Returns the percent of individuals with the dominant phenotype
double Species::findPercentDominant() const
{
  return (pAlleleFrequency * pAlleleFrequency) + (2 * pAlleleFrequency
  * getQAlleleFrequency());
}

//returns the number of individuals with the dominant phenotype
double Species::findNumberDominant() const
{
  return static_cast<int>(findPercentDominant() * size);
}

//returns the percent of individuals with the recessive phenotype
double Species::findPercentRecessive() const
{
  return (getQAlleleFrequency() * getQAlleleFrequency());
}

//returns the number of individuals with the recessive phenotype
double Species::findNumberRecessive() const
{
  return static_cast<int>(findPercentRecessive() * size);
}

//deteremines whether a population is in equilibrium
bool Species::equilibrium( double dominant, double heterozygous, double
recessive)
{
  double pAllele = (dominant * 2 + heterozygous) / 2;
  double qAllele = (recessive * 2 + heterozygous) / 2;
  if (dominant == pAllele * pAllele && heterozygous == 2 * pAllele *
  qAllele && recessive == qAllele * qAllele)
    return true;
  else
    return false;
}








