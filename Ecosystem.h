// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/9/18
// Class: CS 172

#ifndef ECOSYSTEM_H_
#define ECOSYSTEM_H_
#include <vector>
#include "Species.h"
#include "IndependentSpecies.h"
#include "PredatorPrey.h"

class Ecosystem
{
public:
  Ecosystem();
  int getNumberSpecies() const;
  int getNumberIndependentSpecies() const;
  int getNumberPredatorPrey() const;
  vector<Species*> getAllSpecies() const;
  void addSpecies(const Species& species);
  void addIndependentSpecies(const IndependentSpecies& 
  independentSpecies);
  void addPredatorPrey(const PredatorPrey& predatorPrey);
private:
  //can also hold objects of type IndependentSpecies or PredatorPrey
  vector<Species*> allSpecies;
  //total number of species, predator/prey sets counted as one
  int numberSpecies; 
  int numberIndependentSpecies;
  int numberPredatorPrey;

};

#endif