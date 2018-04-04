#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{

    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");


    /// Un exemple de graphe
    Graph g;
    g.make_example();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();
        rect(grman::page,25,250,50,275,makecol(0,0,0));
        rect(grman::page,25,300,50,325,makecol(0,0,0));
        rect(grman::page,25,350,50,375,makecol(0,0,0));
        rect(grman::page,25,400,50,425,makecol(0,0,0));


        textprintf(grman::page,font,55,260,makecol(255,255,255),"k-connexit�");



        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


