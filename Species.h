// Project Name: Final Project
// Name: Allysa Sewell
// Date: 6/8/18
// Class: CS 172

#ifndef SPECIES_H_
#define SPECIES_H_
#include <string>
using namespace std;

class Species
{
public:
  Species();
  Species(string name, double size, double pAlleleFrequency);
  Species(const Species&);
  //function is virtual to support polymorphism
  string getName() const;
  virtual void setName(string name);
  double getSize() const;
  void setSize(double size);
  double getPAlleleFrequency() const;
  void setPAlleleFrequency( double pAlleleFrequency);
  double getQAlleleFrequency() const;
  double findHomozygousDominant() const;
  double findHeterozygous() const;
  double findHomozygousRecessive() const;
  double findPercentDominant() const;
  double findNumberDominant() const;
  double findPercentRecessive() const;
  double findNumberRecessive() const;
  static bool equilibrium( double dominant, double heterozygous, double
  recessive);
protected: //can be accessed by derived classes
  double size;
  string name;
  double pAlleleFrequency;
};

#endif
