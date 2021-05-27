#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "support_a_dessin.h"
class Vecteur3D{
    public:
    double x;
    double y;
    double z;
    Vecteur3D(double x_,double y_,double z_){
        x=x_;
        y=y_;
        z=z_;
    }
};

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Contenu const& a_dessiner) override;
  virtual void dessine(Montagne_simple const& a_dessiner) override;
  virtual void dessine(ChaineMontagne const& a_dessiner) override;
  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(ChampPotentiels const& a_dessiner) override;
  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessinecarre(QMatrix4x4 const& point_de_vue, Vecteur3D p1, Vecteur3D p2, Vecteur3D p3, Vecteur3D p4);
  void dessinevecteur(QMatrix4x4 const& point_de_vue, Vecteur3D v);
 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;
};

