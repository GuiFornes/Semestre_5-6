#include "personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("Epée rouillée"), m_degatsArme(10)
{
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_nomArme(nomArme), m_degatsArme(degatsArme)
{
}

void Personnage::recevoirDegats(int nbDegats)
{
    //On enlève à la vie les dégats reçus
    m_vie -= nbDegats;

    //Si on a dépasser 0 on remet la vie à 0 (mort)
    if ( m_vie < 0 ){
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_degatsArme);
    //On inflige à la cible les dégâts que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;
    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_nomArme = nomNouvelleArme;
    m_degatsArme = degatsNouvelleArme;
}

bool Personnage::estVivant()
{
    return m_vie > 0;
}
