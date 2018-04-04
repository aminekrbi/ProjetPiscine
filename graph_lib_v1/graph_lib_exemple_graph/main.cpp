#include "grman/grman.h"
#include <iostream>

#include "graph.h"
affichagegraph(Graph g, int choixgraph)
{
    int it=choixgraph;
    if (choixgraph<4)
    {
        while (!key[KEY_ESC] && choixgraph==it)
        {
            g.update();
            grman::mettre_a_jour();

            if (mouse_b&1 && (mouse_x<100 && mouse_x>15) && (mouse_y<100 && mouse_y>15))
                {
                    choixgraph--;
                    return choixgraph;
                }
            if (mouse_b&1 && (mouse_x<1000 && mouse_x>915) && (mouse_y<100 && mouse_y>15))
                {
                    choixgraph++;
                    return choixgraph;
                }
        }
    }
}
int main()
{
    ///variables

    int choixgraph=2;
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
        g.update();
            if(mouse_b&1 && (mouse_x<100 && mouse_x>15) && (mouse_y<100 && mouse_y>15))
            {
                choixgraph--;
                choixgraph=affichagegraph(g,choixgraph);
            }
            if(mouse_b&1 && (mouse_x<1000 && mouse_x>915) && (mouse_y<100 && mouse_y>15))
            {
                   choixgraph++;
                   choixgraph=affichagegraph(g,choixgraph);
            }
        /// Mise à jour générale (clavier/souris/buffer etc...)
        //grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


