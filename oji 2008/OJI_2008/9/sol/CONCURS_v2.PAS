{Serban Marinel - 100 puncte}
Program Concurs;
CONST MAXJ  =  52;
      MAXEJ = 500;
      MAXE  = 1000;
      INFILE = 'concurs.in';
      OUTFILE = 'concurs.out';
Type Judet = Array[-1..MAXEJ] Of Integer;

Var Fin, Fout: Text;
    E: Array[1..MAXJ] Of Judet; {-1 - judet, 0 - nr_elevi_judet}
    P, NJ, i: Integer;

Procedure Citire;
Var i, j, Jud, Elev: Integer;
Begin
  Assign(Fin, INFILE); Reset(Fin);
  ReadLn(Fin, P);
  For i := 1 To P Do
    Begin
      ReadLn(Fin, Jud, Elev);
      j := 1;
      While (j<=NJ) AND (E[j][-1]<>Jud) Do Inc(j);
      If j<=NJ Then     {a mai fost judetul}
        Begin           {pun in el}
          Inc(E[j][0]);          {numar inca un elev in acest judet}
          E[j][E[j][0]] := Elev  {il pun la locul lui}
        End
      Else
        Begin           {judet nou}
          Inc(NJ); E[NJ][-1] := Jud;{al catelea este}
          Inc(E[NJ][0]);         {numar un elev in acest judet}
          E[NJ][E[NJ][0]] := Elev{il pun la locul lui}
        End;
    End;
  Close(Fin)
End;

Procedure Sort_Judet;
Var Aux: judet;      {sortez judetele crescator dupa codul judetului}
    i, j, Poz: Integer;
    MinJ: Integer;
Begin
  For i := 1 To NJ-1 Do
    Begin
      MinJ := E[i][-1]; Poz := i;
      For j := i+1 To NJ Do
        If E[j][-1]<MinJ Then
          Begin
            MinJ := E[j][-1]; Poz := j;
          End;
      Aux := E[Poz]; E[Poz] := E[i]; E[i] := Aux
    End;
End;

Procedure Sort_Jud(k: Integer); {sortez elevii din judetul k}
Var i, j, Poz: Integer;         {crescator dupa codul elevilor }
    Min: Integer;
Begin
  For i := 1 To E[k][0]-1 Do
    Begin
      Min := E[k][i]; Poz := i;
      For j := i+1 To E[k][0] Do
        If E[k][j]<Min Then
          Begin
            Min := E[k][j]; Poz := j;
          End;
      E[k][Poz] := E[k][i]; E[k][i] := Min
    End;
End;

Procedure Muta(k1, k2: Integer);
Var i: Integer;
Begin
  For i := 1 To E[k1][0]-1 Do
    E[k1][i] := E[k1][i+1];
  E[k1][E[k1][0]] := 0;
  Dec(E[k1][0]);
  For i := 1 To E[k2][0]-1 Do
    E[k2][i] := E[k2][i+1];
  E[k2][E[k2][0]] := 0;
  Dec(E[k2][0]);
End;

Procedure Repartizeaza;
Var Max1, Max2: Integer;
    i, j, Afisati, JPrec: Integer;
    SePoate: Boolean;
Begin
  Afisati := 0; JPrec := 0;
  SePoate := TRUE;
  While (Afisati<P) AND SePoate Do
    Begin
      If E[1][0]<E[2][0] Then    {determin cele 2 mai numeroase}
        Begin
          Max1 := 2; Max2 := 1
        End
      Else
        Begin
          Max2 := 2; Max1 := 1
        End;
      For i := 3 To NJ Do
        If E[i][0]>E[Max1][0] Then
          Begin Max2 := Max1; Max1:= i End
        Else
          If E[i][0]>E[Max2][0] Then
            Max2 := i;
      If E[Max1][0]>1 Then
        Begin
          If E[Max1][-1]<>Jprec Then
            Begin
              WriteLn(Fout, E[Max1][-1], ' ', E[Max1][1]);
              WriteLn(Fout, E[Max2][-1], ' ', E[Max2][1]);
              JPrec := E[Max2][-1]
            End
          Else
            Begin
              WriteLn(Fout, E[Max2][-1], ' ', E[Max2][1]);
              WriteLn(Fout, E[Max1][-1], ' ', E[Max1][1]);
              JPrec := E[Max1][-1]
            End;
          Inc(Afisati, 2);
          Muta(Max1, Max2);
        End
      Else
        SePoate := FALSE
    End;
  While Afisati<P Do   {au mai ramas cu cate 1 maxim}
    Begin
      For i := 1 To NJ Do
        If (E[i][0]>0) AND (E[i][-1]<>JPrec) Then
          Begin
            WriteLn(Fout, E[i][-1], ' ', E[i][1]);
            E[i][0] := 0;
            JPrec := E[i][-1];
            Inc(Afisati)
          End;
    End;
End;

Begin
  Citire;
  Sort_Judet;
  Assign(Fout, OUTFILE); ReWrite(Fout);
  WriteLn(Fout, NJ);
  For i := 1 To NJ Do
    Begin
      Write(Fout, E[i][0], ' ');
      Sort_Jud(i)
    End;
  WriteLn(Fout);
  Repartizeaza;
  Close(Fout)
End.
