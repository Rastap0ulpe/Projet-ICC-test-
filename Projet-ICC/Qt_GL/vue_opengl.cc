#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "contenu.h"
#include "MontagneSimple.h"
#include "Systeme.h"
#include "ChampPotentiels.h"
// ======================================================================
void VueOpenGL::dessine(Contenu const& a_dessiner)
{/*
   // Dessine le 1er cube (à l'origine)
    QMatrix4x4 matrice;
    matrice.translate(15,15,30);
  dessineCube(matrice);

  QMatrix4x4 matrice;
  // Dessine le 2e cube
  matrice.translate(0.0, 1.5, 0.0);
  matrice.scale(0.25);
  dessineCube(matrice);

  // Dessine le 3e cube
  matrice.setToIdentity();
  matrice.translate(0.0, 0.0, 1.5);
  matrice.scale(0.25);
  matrice.rotate(45.0, 0.0, 1.0, 0.0);
  dessineCube(matrice);

  // Dessine le 4e cube
  matrice.setToIdentity();
  matrice.rotate(a_dessiner.infos(), 1.0, 0.0, 0.0);
  matrice.translate(0.0, 2.3, 0.0);
  matrice.scale(0.2);
  dessineCube(matrice);
  */
}

void VueOpenGL::dessine(Montagne_simple const& a_dessiner){
    int max_x(30);
    int max_y(30);


    QMatrix4x4 matrice;
    prog.setAttributeValue(CouleurId,0.5, 0.5, 0.5);
  matrice.setToIdentity();
      for(int i=0;i<max_x;i++){
          for(int j=0;j<max_y;j++){

                Vecteur3D v1(i,j,a_dessiner.altitude(i,j));
                Vecteur3D v2(i+1,j,a_dessiner.altitude(i+1,j));
                Vecteur3D v3(i,j+1,a_dessiner.altitude(i,j+1));
                Vecteur3D v4(i+1,j+1,a_dessiner.altitude(i+1,j+1));

                dessinecarre(matrice,v1,v2,v3,v4);
                //dessineCube(matrice);

        };
      };

      }

void VueOpenGL::dessinecarre(QMatrix4x4 const& point_de_vue, Vecteur3D p1, Vecteur3D p2, Vecteur3D p3, Vecteur3D p4){
      prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

       glBegin(GL_TRIANGLE_STRIP);


         prog.setAttributeValue(SommetId, p1.x, p1.y, p1.z);
         prog.setAttributeValue(SommetId, p2.x, p2.y, p2.z);
         prog.setAttributeValue(SommetId, p3.x, p3.y, p3.z);
         prog.setAttributeValue(SommetId, p4.x, p4.y, p4.z);



        glEnd();
}



void VueOpenGL::dessine(ChaineMontagne const& a_dessiner){


}

void VueOpenGL::dessine(Systeme const& a_dessiner){
QMatrix4x4 matrice;
matrice.setToIdentity();

if(a_dessiner.oui){
    dessineCube(matrice);
}

prog.setAttributeValue(CouleurId, 0.75, 0.75, 0.75);

int a(a_dessiner.get_ciel().taille_x());
int b(a_dessiner.get_ciel().taille_y());
int c(a_dessiner.get_ciel().taille_z());

double norme;
Vecteur3D vec(0,0,0);
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                matrice.setToIdentity();
                matrice.translate(i, j, k);


                if(a_dessiner.ciel.nuage(i,j,k)){
                    prog.setAttributeValue(CouleurId, 0.75, 0.75, 0.75);

                    dessineCube(matrice);
                }
                std::vector<double> v(a_dessiner.ciel.air[i][j][k].get_vitesse());
                norme=sqrt(pow(v[0],2)+pow(v[1],2)+pow(v[2],2));
                prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
                if(norme>25){
                vec.x=v[0]/norme;
                vec.y=v[1]/norme;
                vec.z=v[2]/norme;
                dessinevecteur(matrice,vec);
                }
                if(a_dessiner.ciel.air[i][j][k].pluie()){
                    prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
                    dessineCube(matrice);
                }
            }
        }
    }

}

void VueOpenGL::dessine(ChampPotentiels const& a_dessiner){


}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
    matrice_vue.setToIdentity();

    matrice_vue.rotate(300.0, 1.0, 0.0, 0.0);
    matrice_vue.rotate(50.0, 0.0, 0.0, 1.0);
    matrice_vue.translate(5,5,-22);

}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  //prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  //prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  //prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  //prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  //prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  //prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}

void VueOpenGL::dessinevecteur(const QMatrix4x4 &point_de_vue, Vecteur3D v){
    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_LINES);
    //prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);

    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, v.x, v.y, v.z);


    glEnd();


}
