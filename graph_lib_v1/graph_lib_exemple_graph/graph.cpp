#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


/***************************************************
                    VERTEX
****************************************************/

/// Le constructeur met en place les éléments de l'interface
VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name, int pic_idx)
{
    // La boite englobante
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de réglage de valeur
    m_top_box.add_child( m_slider_value );
    m_slider_value.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_value.set_dim(20,80);
    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);

    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }

    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);

    m_box_label_idx.add_child( m_label_idx );
    m_label_idx.set_message( std::to_string(idx) );
}


/// Gestion du Vertex avant l'appel à l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_value vers le slider associé
    m_interface->m_slider_value.set_value(m_value);

    /// Copier la valeur locale de la donnée m_value vers le label sous le slider
    m_interface->m_label_value.set_message( std::to_string( (int)m_value) );
}


/// Gestion du Vertex après l'appel à l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_value locale
    m_value = m_interface->m_slider_value.get_value();
}



/***************************************************
                    EDGE
****************************************************/

/// Le constructeur met en place les éléments de l'interface
EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de réglage associés
    m_top_edge.add_child(m_box_edge);
    m_box_edge.set_dim(24,60);
    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de réglage de valeur
    m_box_edge.add_child( m_slider_weight );
    m_slider_weight.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_weight.set_dim(16,40);
    m_slider_weight.set_gravity_y(grman::GravityY::Up);

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);

}


/// Gestion du Edge avant l'appel à l'interface
void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_weight vers le slider associé
    m_interface->m_slider_weight.set_value(m_weight);

    /// Copier la valeur locale de la donnée m_weight vers le label sous le slider
    m_interface->m_label_weight.set_message( std::to_string( (int)m_weight ) );
}

/// Gestion du Edge après l'appel à l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_weight locale
    m_weight = m_interface->m_slider_weight.get_value();
}



/***************************************************
                    GRAPH
****************************************************/

/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    ///fonds
    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(875,700);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);

    /// boite latérale
    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(100,700);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANC);

    ///suivant précedent +txt + button

    m_tool_box.add_child(aprecedent);
    aprecedent.set_dim(100,100);
    aprecedent.set_pos(0,100);
    aprecedent.set_bg_color(BLEUCLAIR);

    m_tool_box.add_child(precedent);
    precedent.set_dim(75,75);
    precedent.set_pos(10,113);
    precedent.set_bg_color(BLEU);

    m_tool_box.add_child(precedenth);
    precedenth.set_dim(75,75);
    precedenth.set_pos(10,113);
    precedenth.set_bg_color(BLEU);

    m_tool_box.add_child(asuivant);
    asuivant.set_dim(100,100);
    asuivant.set_pos(0,0);
    asuivant.set_bg_color(VERTCLAIR);

    m_tool_box.add_child(suivant);
    suivant.set_dim(75,75);
    suivant.set_pos(10,10);
    suivant.set_bg_color(VERT);

    m_tool_box.add_child(suivanth);
    suivanth.set_dim(75,75);
    suivanth.set_pos(10,10);
    suivanth.set_bg_color(VERT);


    suivanth.add_child(suivanttext);
    suivanttext.set_message("next");

    precedenth.add_child(precedenttext);
    precedenttext.set_message("précédent");



    ///quitter sauvegarder
    m_tool_box.add_child(aquitter);
    aquitter.set_dim(100,75);
    aquitter.set_pos(0,550);
    aquitter.set_bg_color(ROUGECLAIR);

    m_tool_box.add_child(quitter);
    quitter.set_dim(75,50);
    quitter.set_pos(10,563);
    quitter.set_bg_color(ROUGE);

    m_tool_box.add_child(quitterh);
    quitterh.set_dim(75,50);
    quitterh.set_pos(10,563);
    quitterh.set_bg_color(ROUGE);

    m_tool_box.add_child(asauvegarder);
    asauvegarder.set_dim(100,75);
    asauvegarder.set_pos(0,625);
    asauvegarder.set_bg_color(VERTCLAIR);

    m_tool_box.add_child(sauvegarder);
    sauvegarder.set_dim(75,50);
    sauvegarder.set_pos(10,638);
    sauvegarder.set_bg_color(VERT);

    m_tool_box.add_child(sauvegarderh);
    sauvegarderh.set_dim(75,50);
    sauvegarderh.set_pos(10,638);
    sauvegarderh.set_bg_color(VERT);

    sauvegarderh.add_child(sauvegardertext);
    sauvegardertext.set_message("save");

    quitterh.add_child(quittertexte);
    quittertexte.set_message("quit");

    ///connexité

    m_tool_box.add_child(aconnexite);
    aconnexite.set_dim(100,50);
    aconnexite.set_pos(0,500);
    aconnexite.set_bg_color(VERTCLAIR);

    m_tool_box.add_child(connexiteb);
    connexiteb.set_dim(15,15);
    connexiteb.set_pos(5,515);
    connexiteb.set_bg_color(VERT);

    ///k-connexité

    m_tool_box.add_child(akconnexite);
    akconnexite.set_dim(100,50);
    akconnexite.set_pos(0,450);
    akconnexite.set_bg_color(BLEUCLAIR);

    m_tool_box.add_child(kconnexiteb);
    kconnexiteb.set_dim(15,15);
    kconnexiteb.set_pos(5,465);
    kconnexiteb.set_bg_color(BLEU);

    aconnexite.add_child(connexitetext);
    connexitetext.set_message("    F-connexe");

    akconnexite.add_child(kconnexitetext);
    kconnexitetext.set_message("    K-connexe");


    ///ajouter supprimer

    m_tool_box.add_child(ajouth);
    ajouth.set_dim(50,50);
    ajouth.set_pos(0,300);
    ajouth.set_bg_color(ROUGECLAIR);

    m_tool_box.add_child(supprimerh);
    supprimerh.set_dim(50,50);
    supprimerh.set_pos(50,300);
    supprimerh.set_bg_color(BLEUCLAIR);

    supprimerh.add_child(supprimertext);
    supprimertext.set_message("supp");

   ajouth.add_child(ajouttext);
   ajouttext.set_message("add");

   ///play simu
  m_tool_box.add_child(aplay);
    aplay.set_dim(100,50);
    aplay.set_pos(0,400);
    aplay.set_bg_color(BLEUCLAIR);

    m_tool_box.add_child(playb);
    playb.set_dim(15,15);
    playb.set_pos(5,415);
    playb.set_bg_color(BLEU);

    aplay.add_child(playtext);
    playtext.set_message("     Simu");


}

void Graph::ajoutarc1()
{
    int n=0;
    int s1,s2;
    double poid;
    bool possible=false;

    do
    {
        if(m_edges.count(n)==1)
        {
            n++;
        }
        else
        {
            possible=true;
        }
    }while(!possible);

    do
    {
        system("cls");
        std::cout<< "choisir un sommet de depart";
        std::cin>>s1;
        std::cout<< "choisir un sommet de d'arriver";
        std::cin>>s2;
    }while(s1==s2);

    do
    {
        std::cout<<std::endl<< "choisir un poid entre 0 et 420";
        std::cin>>poid;
    }while(poid<0 || poid>420);

    add_interfaced_edge(n,s1,s2,poid);
    system("cls");

}

void Graph::ajoutsommet1()
{
    int n;
    int s1,s2;
    double poid;
    std :: cout<<"choisir le numero du sommet";
    std::cin>>n;

    do
    {
        system("cls");
        std::cout<< "choisir la position x de depart";
        std::cin>>s1;
        std::cout<< "choisir la position y de depart";
        std::cin>>s2;
    }while(s1>800 || s2>800);

    do
    {
        std::cout<<std::endl<< "choisir un poid entre 0 et 100";
        std::cin>>poid;
    }while(poid<0 || poid>100);

    //add_interfaced_vertex(n,poid,s1,s2,"clown1.jpp");
     add_interfaced_vertex(n, poid, s1, s2, "clown1.jpg");
    system("cls");

}

void Graph:: ajout()
{
    int choix=0;
    do
    {
        std::cout<<"1: pour ajouter un arc, 2: pour ajouter une arrete";
        std::cin>>choix;

        if(choix==1)
        {
            ajoutarc1();
        }
        if(choix==2)
        {
            ajoutsommet1();
        }


    }while( choix!=1 || choix!=2);
}
void Graph::remove_edge(int eidx)
{
    /// référence vers le Edge à enlever
    Edge &remed=m_edges.at(eidx);

    std::cout << "Removing edge " << eidx << " " << remed.m_from << "->" << remed.m_to << " " << remed.m_weight << std::endl;

    /// Tester la cohérence : nombre d'arc entrants et sortants des sommets 1 et 2
    std::cout << m_vertices[remed.m_from].m_in.size() << " " << m_vertices[remed.m_from].m_out.size() << std::endl;
    std::cout << m_vertices[remed.m_to].m_in.size() << " " << m_vertices[remed.m_to].m_out.size() << std::endl;
    std::cout << m_edges.size() << std::endl;

    /// test : on a bien des éléments interfacés
    if (m_interface && remed.m_interface)
    {
        /// Ne pas oublier qu'on a fait ça à l'ajout de l'arc :
        /* EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]); */
        /* m_interface->m_main_box.add_child(ei->m_top_edge);  */
        /* m_edges[idx] = Edge(weight, ei); */
        /// Le new EdgeInterface ne nécessite pas de delete car on a un shared_ptr
        /// Le Edge ne nécessite pas non plus de delete car on n'a pas fait de new (sémantique par valeur)
        /// mais il faut bien enlever le conteneur d'interface m_top_edge de l'arc de la main_box du graphe
        m_interface->m_main_box.remove_child( remed.m_interface->m_top_edge );
    }

    /// Il reste encore à virer l'arc supprimé de la liste des entrants et sortants des 2 sommets to et from !
    /// References sur les listes de edges des sommets from et to
    std::vector<int> &vefrom = m_vertices[remed.m_from].m_out;
    std::vector<int> &veto = m_vertices[remed.m_to].m_in;
    vefrom.erase( std::remove( vefrom.begin(), vefrom.end(), eidx ), vefrom.end() );
    veto.erase( std::remove( veto.begin(), veto.end(), eidx ), veto.end() );

    /// Le Edge ne nécessite pas non plus de delete car on n'a pas fait de new (sémantique par valeur)
    /// Il suffit donc de supprimer l'entrée de la map pour supprimer à la fois l'Edge et le EdgeInterface
    /// mais malheureusement ceci n'enlevait pas automatiquement l'interface top_edge en tant que child de main_box !
    m_edges.erase( eidx );


    /// Tester la cohérence : nombre d'arc entrants et sortants des sommets 1 et 2
    std::cout << m_vertices[remed.m_from].m_in.size() << " " << m_vertices[remed.m_from].m_out.size() << std::endl;
    std::cout << m_vertices[remed.m_to].m_in.size() << " " << m_vertices[remed.m_to].m_out.size() << std::endl;
    std::cout << m_edges.size() << std::endl;

}
void Graph::suppsommet(int choisommet)
{
    Vertex &remed=m_vertices.at(choisommet);

    if(m_interface && remed.m_interface)
    {
        m_interface->m_main_box.remove_child(remed.m_interface->m_top_box);
    }

for(int i=0; i<11; i++)
    if(m_edges[i].m_from == choisommet || m_edges[i].m_to == choisommet)

    remove_edge(i);
}

void Graph:: supp()
{
    int choix=0;
    int choisommet;
    int choiarrete;
    do
    {
        std::cout<<"1: pour supprimer un sommet, 2: pour supprimer une arrete"<<std::endl;
        std::cin>>choix;

        if(choix==1)
        {
            std ::cout << "choisir le numero de du sommet"<<std::endl;
            std::cin>>choisommet;
            suppsommet(choisommet);
        }
        if(choix==2)
        {
            std::cout<<"choisir le numero de l'arc"<<std::endl;
            std::cin>>choiarrete;
            remove_edge(choiarrete);

        }


    }while( choix!=1 && choix!=2);
}

void Graph::kconnexite()
{
    int nmsommet=0;
    int tab[10];
    std::cout <<"mzdic";

/*        nmsommet=parcourarretemin(nmsommet);
        tab[10]=matriceadjacent();

        for(int i=0;i<10;i++)
        {
            suppsommet(tab(i));
            //desactivesommetarc(tab[i]);
        }*/
}
/// Méthode spéciale qui construit un graphe arbitraire (démo)
/// Cette méthode est à enlever et remplacer par un système
/// de chargement de fichiers par exemple.
/// Bien sûr on ne veut pas que vos graphes soient construits
/// "à la main" dans le code comme ça.
void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);

    //loadfic(fic);

    /// Les sommets doivent être définis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
    add_interfaced_vertex(0, 30.0, 200, 100, "clown1.jpg");
    add_interfaced_vertex(1, 60.0, 400, 100, "clown2.jpg");
    add_interfaced_vertex(2,  50.0, 200, 300, "clown3.jpg");
    add_interfaced_vertex(3,  0.0, 400, 300, "clown4.jpg");
    add_interfaced_vertex(4,  100.0, 600, 300, "clown5.jpg");
    add_interfaced_vertex(5,  0.0, 100, 500, "bad_clowns_xx3xx.jpg", 0);
    add_interfaced_vertex(6,  0.0, 300, 500, "bad_clowns_xx3xx.jpg", 1);
    add_interfaced_vertex(7,  0.0, 500, 500, "bad_clowns_xx3xx.jpg", 2);

    /// Les arcs doivent être définis entre des sommets qui existent !
    // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
    add_interfaced_edge(0, 1, 2, 50.0);
    add_interfaced_edge(1, 0, 1, 50.0);
    add_interfaced_edge(2, 1, 3, 75.0);
    add_interfaced_edge(3, 4, 1, 25.0);
    add_interfaced_edge(4, 6, 3, 25.0);
    add_interfaced_edge(5, 7, 3, 25.0);
    add_interfaced_edge(6, 3, 4, 0.0);
    add_interfaced_edge(7, 2, 0, 100.0);
    add_interfaced_edge(8, 5, 2, 20.0);
    add_interfaced_edge(9, 3, 7, 80.0);

}

/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update()
{
    if (!m_interface)
        //return 0;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();

       /* ///connexe
        if(m_interface->kconnexiteb.Checked())
        {
            kconnexite();
        }
        if(m_interface->connexiteb.clicked())
        {
            //fconexite();
        }*/

        ///save quit
        if(m_interface->sauvegarderh.clicked())
        {
            std::cout<< "sisi";//ajoutsommet1();
        }
        if(m_interface->quitterh.clicked())
        {
            exit(0);
        }

        ///ajout & supp
        if(m_interface->ajouth.clicked())
        {
            ajout();
        }
        if(m_interface->supprimerh.clicked())
        {
            supp();
        }


}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);
}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);

        m_edges[idx].m_from = id_vert1;
    m_edges[idx].m_to = id_vert2;

    m_vertices[id_vert1].m_out.push_back(idx);
    m_vertices[id_vert2].m_in.push_back(idx);

}
