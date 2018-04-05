#include "grman/grman.h"
#include <iostream>

#include "graph.h"
void affichagegraph(Graph g)
{

    /// Le nom du répertoire où se trouvent les images à charger
    g.update();
    grman::mettre_a_jour();

    while(!key[KEY_ESC] )

        {
            g.update();
            grman::mettre_a_jour();
        }
}

void menu(Graph g,Graph i,Graph j)
{
    int choixgraph=1;

    if (choixgraph<4 && choixgraph>0)
    {
        while (!key[KEY_ESC])
        {

            if (mouse_b&1 && (mouse_x<100 && mouse_x>15) && (mouse_y<100 && mouse_y>15))
                {
                    if (choixgraph==1)
                    {
                        affichagegraph(g);
                        choixgraph=1;
                    }
                    if(choixgraph==2)
                    {
                        choixgraph--;
                        affichagegraph(g);
                    }
                    if(choixgraph==3)
                    {
                        choixgraph--;
                        affichagegraph(i);
                    }
                }
            if (mouse_b&1 && (mouse_x<1000 && mouse_x>915) && (mouse_y<100 && mouse_y>15))
                {
                    if (choixgraph==1)
                    {
                        affichagegraph(i);
                        choixgraph++;

                    }
                    if(choixgraph==2)
                    {
                        choixgraph++;
                        affichagegraph(j);

                    }
                    if(choixgraph==3)
                    {
                        choixgraph=3;
                        affichagegraph(j);

                    }
                }
        }
   }

   if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<725 && mouse_y>680))
    {
                //sauvegarde();
    }

            ///simulation
    if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
    {
                //simulation();
    }
    if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
    {

    }

            ///conexite
    if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
    {
                //connexite(g,choixgraph)
    }

            ///ajout sommet
    if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
    {

    }
    if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<800 && mouse_y>725))
    {

    }
}

///simulation(Graph g,)

/*
{

if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
            {

            }
}
            */

///sauvegarde(Graph g)

/*
{

}
*/

///connexite(Graph g,int choixgraph)
/*
{

}
*/

int main()
{
    ///variables

    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    Graph i;
    Graph j;


    g.make_example();   /// Un exemple de graphe
   // i.make_example();
    //j.make_example();
    //g.loadfic("sauvegarderg1.txt");
    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    //while ( !key[KEY_ESC] )

        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        //choixgraph=menu(g,choixgraph);

        //grman::mettre_a_jour();

        while(!key[KEY_ESC] )

        {
            //choixgraph=menu(g,choixgraph);
            affichagegraph(g);
            menu(g,i,j);

        }
            ///texte suivant prece ...


        /// Mise à jour générale (clavier/souris/buffer etc...)
        //grman::mettre_a_jour();


    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


