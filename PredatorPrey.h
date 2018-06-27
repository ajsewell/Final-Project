// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/8/18
// Class: CS 172

#ifndef PREDATORPREY_H_
#define PREDATORPREY_H_
#include "Species.h"

class PredatorPrey: public Species
{
public:
  PredatorPrey();
  PredatorPrey(string name, double size, double time, double growthRate,
  double pAlleleFrequency);
  PredatorPrey(string name, string Predatorname, double size, double
  predatorSize, double time, double growthRate, double deathRate, double
  alpha, double gamma);
  PredatorPrey(const PredatorPrey&);
  string getPredatorName() const;
  void setPredatorName(string predatorName);
  double getPredatorSize() const;
  void setPredatorSize(double predatorSize);
  double getPredatorDeathRate() const;
  void setPredatorDeathRate(double deathRate);
  double getTime() const;
  void setTime(double time);
  double getPreyGrowthRate() const;
  double getAlpha() const;
  void setAlpha(double alpha);
  double getGamma() const;
  void setGamma(double gamma);
  double calculatePreyPopulation();
  double calculatePredatorPopulation();
private:
  string predatorName;
  double predatorSize;
  double preyGrowthRate;
  double predatorDeathRate;
  double time;
  double alpha;
  double gamma;
  double findPhi() const;
  double findK() const;
  bool isValid() const;

};

#endif