#pragma once

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "..\..\MontagneSimple.h"
#include "..\..\Systeme.h"

class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(Montagne*  m , unsigned int N_x,unsigned int N_y,unsigned int N_z, double lambda, QWidget* parent = nullptr)
    : QOpenGLWidget(parent), S(m,N_x,N_y,N_z,lambda)
  {
      M=std::unique_ptr<Montagne>(m);
      S.initialise_ciel();

  }
  virtual ~GLWidget() = default;
  void pause();

  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne


  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évolue
  std::unique_ptr<Montagne> M;
  Systeme S;


};
