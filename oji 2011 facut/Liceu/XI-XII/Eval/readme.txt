- Important! Nu este recomandabil ca evaluarea sa se faca pe Windows 7 

- Pe sistemul pe care se face evaluarea, trebuie sa fie instalat kit-ul OJI 
  (preferabil atat MinGW Developer Studio, cat si Free Pascal)

- Se instaleaza evaluatorul lansand setup.exe.

- Daca nu exista .NET Framework 3.5, atunci setup-ul il va instala online de pe site-ul Microsoft (dureaza destul de mult)

- Se lanseaza evaluatorul (shortcut pe desktop).

- Se copiaza sursele concurentilor in folderele: 
          Eval_OJI_2011_XI_XII\probleme\[nume_problema_1]\surse_concurenti 
	
	  Eval_OJI_2011_XI_XII\probleme\[nume_problema_2]\surse_concurenti

- Optional, se pot importa datele concurentilor dintr-un fisier .xls. [Setari->Concurenti->Importa]


COMPILARE
   Comisia poate alege mai multe variante de compilare

Exemple:
1. In panoul de compilare, se bifeaza checkbox-ul "Toate problemele", 
   apoi se apasa butonul "Compileaza"
2. Se selecteaza o singura problema, se bifeaza checkbox-ul "Toate" si se compileaza doar sursele acelei probleme.
 

EVALUARE
   Comisia poate alege mai multe variante de evaluare.

Exemple:
1. In panoul de evaluare, se bifeaza checkbox-ul "Toate problemele", apoi se apasa Evalueaza. 
   Astfel se evalueaza toate sursele ambelor probleme, pe toate testele. 

2. Se selecteaza un singur executabil, se bifeaza "Test cu test". 

 
RAPOARTE
   Atat rapoartele de compilare, cat si cele de evaluare, se acceseaza din meniu.
   Evaluatorul produce si fisierul Clasament.xls. 

IMPORTANT !!!

   Evaluatorul nu pastreaza rapoartele primei probleme evaluate decat in cazul 1 de evaluare (bifa pe "Toate problemele").
  
   Daca se evalueaza toate executabilele pentru o singura problema sau se evalueaza "Test cu test" 
   atunci este indicat sa se salveze rapoartele (copiere manuala din Evaluator\rapoarte\evaluare),
   urmand sa se continue cu evaluarea celei de-a doua probleme.
