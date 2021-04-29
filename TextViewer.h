#pragma once
 
#include <iostream>
#include "SupportADessin.h"
 
class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete; 
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default; 
  TextViewer& operator=(TextViewer&&) = default;
 
 virtual void dessine(Systeme  const& system) override;
  //virtual void dessine(Montagne const& M) override; 
private:
  std::ostream& flot;
};
