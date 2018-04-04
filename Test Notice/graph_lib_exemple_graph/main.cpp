#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    bool line1 = false;
    bool line2 = false;
    bool line3 = false;
    bool line4 = false;
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
        rect(grman::page,25,250,50,275,makecol(0,0,0));
        rect(grman::page,25,300,50,325,makecol(0,0,0));
        rect(grman::page,25,350,50,375,makecol(0,0,0));
        rect(grman::page,25,400,50,425,makecol(0,0,0));
///Algorithme pour cocher les cases choisis
        if(mouse_b&1 && mouse_x>25 && mouse_x<50 && mouse_y>250 && mouse_y<275 )
        {
            line1=true;
            line2=false;
            line3=false;
            line4=false;
        }

        if(line1 == true)
        {
            line(grman::page,25,250,50,275,makecol(255,0,0));
        }

        if(mouse_b&1 && mouse_x>25 && mouse_x<50 && mouse_y>300 && mouse_y<325)
        {
            line2=true;
            line1=false;
            line3=false;
            line4=false;
        }

        if(line2 == true)
        {
            line(grman::page,25,300,50,325,makecol(255,0,0));
        }

        if(mouse_b&1 && mouse_x>25 && mouse_x<50 && mouse_y>350 && mouse_y<375)
        {
            line3=true;
            line2=false;
            line1=false;
            line4=false;
        }

        if(line3 == true)
        {
            line(grman::page,25,350,50,375,makecol(255,0,0));
        }

        if(mouse_b&1 && mouse_x>25 && mouse_x<50 && mouse_y>400 && mouse_y<425)
        {
            line4=true;
            line2=false;
            line3=false;
            line1=false;
        }

        if(line4 == true)
        {
            line(grman::page,25,400,50,425,makecol(255,0,0));

        }

///Algorithme pour décocher
        if(mouse_b&2 && mouse_x>25 && mouse_x<50 && mouse_y>250 && mouse_y<275 && line1 == true)
        {
            line1 = false;
        }

        if(mouse_b&2 && mouse_x>25 && mouse_x<50 && mouse_y>300 && mouse_y<325 && line2 == true)
        {
            line2 = false;
        }

        if(mouse_b&2 && mouse_x>25 && mouse_x<50 && mouse_y>350 && mouse_y<375 && line3 == true)
        {
            line3 = false;
        }

        if(mouse_b&2 && mouse_x>25 && mouse_x<50 && mouse_y>400 && mouse_y<425 && line4 == true)
        {
            line4 = false;
        }



        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


