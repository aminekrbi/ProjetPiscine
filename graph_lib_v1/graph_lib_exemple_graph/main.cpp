#include "grman/grman.h"
#include <iostream>

#include "graph.h"
void affichagegraph(Graph g)
{

    /// Le nom du répertoire où se trouvent les images à charger
    g.update();
    grman::mettre_a_jour();

 /*   while(!key[KEY_ESC] )

        {
            g.update();
            grman::mettre_a_jour();
        }*/
}

/*oid ajoutsommet()
{
    std::string nomsaisie;
    std::cin>>nomsaisie;

    if (nomsaisie=="clown1")
    {
        add_interfaced_vertex(0, 30.0, 200, 100, "clown1.jpg");
    }
    else
    {
            std::cout << "pas d'image de ce type ";
    }
}
*/
int menu(Graph g,int choixgraph)
{
    //affichagegraph(g);
    //std ::cout<< "bienvenue";

    g.update();
    //grman::mettre_a_jour();

    while (!key[KEY_ESC])
        {
            g.update();
            grman::mettre_a_jour();

            if (choixgraph<4 && choixgraph>0)
            {

            ///suivant precedent
            if (mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<200 && mouse_y>100))
                {
                    std ::cout<< "bienvenue";
                    //g.ajoutarc1();
                   // std ::cout<< "bienvenue";
                    if (choixgraph==1)
                    {
                       // affichagegraph(g);
                        choixgraph=1;
                        return choixgraph;
                    }
                    if(choixgraph==2)
                    {
                        choixgraph--;
                        //affichagegraph(g);
                        return choixgraph;
                    }
                    if(choixgraph==3)
                    {
                        choixgraph--;
                        return choixgraph;
                        //affichagegraph(i);
                    }
                }
            if (mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<100 && mouse_y>0))
                {
                    std ::cout<<"bienvenue";
                    //g.ajoutarc1();
                    if (choixgraph==1)
                    {
                        //affichagegraph(i);
                        choixgraph++;
                        return choixgraph;

                    }
                    if(choixgraph==2)
                    {
                        choixgraph++;
                        return choixgraph;
                        //affichagegraph(j);

                    }
                    if(choixgraph==3)
                    {
                        choixgraph=3;
                        return choixgraph;
                        //affichagegraph(j);

                    }
                }
            }
        }
}
            /*
            if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<550 && mouse_y>500))
    {


    }

    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<500 && mouse_y>450))
    {

    }

    ///quitter et sauvegarder
    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<625 && mouse_y>550))
    {
            std::cout<<"bien";
    }

    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<700 && mouse_y>625))
    {
               //sauvegarder
    }

            ///ajout et supp sommet
    if(mouse_b&1 && (mouse_x<50 && mouse_x>0) && (mouse_y<300 && mouse_y>350))
    {
        g.ajoutarc1();
    }
    if(mouse_b&1 && (mouse_x<100 && mouse_x>50) && (mouse_y<300 && mouse_y>350))
    {

    }
   }

   ///connexite et k-connexite

   if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<550 && mouse_y>500))
    {


    }

    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<500 && mouse_y>450))
    {

    }

    ///quitter et sauvegarder
    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<625 && mouse_y>550))
    {

    }

    if(mouse_b&1 && (mouse_x<100 && mouse_x>0) && (mouse_y<700 && mouse_y>625))
    {
               //sauvegarder
    }

            ///ajout et supp sommet
    if(mouse_b&1 && (mouse_x<50 && mouse_x>0) && (mouse_y<300 && mouse_y>350))
    {
        g.ajoutarc1();
    }
    if(mouse_b&1 && (mouse_x<100 && mouse_x>50) && (mouse_y<300 && mouse_y>350))
    {

    }
}


///simulation(Graph g,)

{

if(mouse_b&1 && (mouse_x<80 && mouse_x>0) && (mouse_y<100 && mouse_y>15))
            {

            }
}


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
    int choixgraph=1;
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

        while(!key[KEY_ESC] )

        {
            if (choixgraph==1)
            {
                choixgraph=menu(g,choixgraph);
            }
            if (choixgraph==2)
            {
                choixgraph=menu(i,choixgraph);
            }
            if (choixgraph==3)
            {
                choixgraph=menu(j,choixgraph);
            }

        }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


