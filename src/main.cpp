#include <Arduino.h>

#include <iostream>
//using namespace std;


//********************************************************************************
// Classe Etudiant
//********************************************************************************

//Déclaration de la classe Etudiant
class etudiant {
    int numeroMatricule;
    int moyenne;
	
public:
    void setMatricule(int);
    int getMatricule();
    void setMoyenne(int);
    int getMoyenne();
};

//Définition de la méthode setMatricule de la classe, permet de modifier le matricule de l'étudiant
void etudiant::setMatricule(int nouveauMatricule){
    //Le numÃ©rod de matricule doit nÃ©cessairement avoir 6 chiffres
    if ((nouveauMatricule >= 100000) && (nouveauMatricule <= 999999)){
        this->numeroMatricule = nouveauMatricule;    
    }
    else{
        this->numeroMatricule = 999999;
    }
}



int etudiant::getMatricule(void){
    return (this->numeroMatricule);
}

void etudiant::setMoyenne(int nouvelleMoyenne){
    if (nouvelleMoyenne <= 100){
        this->moyenne = nouvelleMoyenne;
    }
    else{
        this->moyenne = 100;
    }
}

int etudiant::getMoyenne(void){
    return (this->moyenne);
}

//********************************************************************************
// Classe EtudiantMusique
//********************************************************************************

//********************************************************************************
// Classe EtudiantTGE
//********************************************************************************

//********************************************************************************
// Classe EtudiantArtLettre
//********************************************************************************

//********************************************************************************
// Classe EtudiantAdmin
//********************************************************************************

//********************************************************************************
// Setup (est appelé seulement une fois au début du programme)
//********************************************************************************

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);    // LED pin as output.
}


//********************************************************************************
// Loop (est appelé en boucle pour l'exécution du programme)
//********************************************************************************

void loop() {
  int numeroMatriculeTmp;
  int moyenneTmp;
  static bool premiereIteration = true;

  if (premiereIteration){
    //On entre dans cette boucle seulement lors de la première itération

    printf("Hello world !\n\n");
  
    etudiant etudiant1;
    etudiant1.setMatricule(111111);
    etudiant1.setMoyenne(80);
    numeroMatriculeTmp = etudiant1.getMatricule();
    moyenneTmp = etudiant1.getMoyenne(); 
    printf("Etudiant1, matricule # %d, moyenne %d\n", numeroMatriculeTmp, moyenneTmp);

    premiereIteration = false;
  }

  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));   // toggle led

  delay(1000);                       // wait for a second
}

