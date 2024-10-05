{Serban Marinel - 100 puncte
 februarie 2011}
Program Comparatii;

Var Fin, Fout: Text;
    Linie, E1, E2: String;
    N, op, l, p, k, Cate: Integer;
    V1, V2: LongInt;
    Rez: Array[1..2000] Of Byte;

Function Eval(E: String; Lung: Byte): LongInt;
Var nr: String;
    i: Byte;
    c: Char;
    v, x: LongInt;
    Code: Integer;

    Procedure Aduna;
    Begin
      c := E[i];   {este m,s,z sau u}
      Val(nr, x, Code);
      Case c Of
        'm': v := v + 1000 * x;
        's': v := v + 100 * x;
        'z': v := v + 10 * x;
        'u': v := v + 1 * x;
      End;
    End;

Begin
  i := 1;
  v := 0;
  While (i <= Lung) Do
    Begin
      nr := '';
      While (E[i] In ['0'..'9']) AND (i <= Lung) Do
        Begin
          nr := nr + E[i];
          Inc(i);
        End;
      Aduna;
      Inc(i);
    End;
  Eval := v
End;

Begin
  Assign(Fin, 'comp.in'); Reset(Fin);
  Assign(Fout, 'comp.out'); ReWrite(Fout);
  ReadLn(Fin, N);
  For k := 1 To N Do
    Begin
      ReadLn(Fin, Linie); l := Length(Linie);
      p := Pos('<', Linie);
      If p = 0 Then
        Begin
          p := Pos('>', Linie);
          op := 2;    {este E1>E2}
        End
      Else
        Begin
          op := 1;      {este E1<E2}
          Inc(Cate)
        End;
      E1 := Copy(Linie, 1, p-1);
      E2 := Copy(Linie, p+1, 250);
      V1 := Eval(E1, p-1);
      V2 := Eval(E2, l-p);
      If op = 1 Then
        If V1<V2 Then Rez[k] := 1
        Else Rez[k] := 0
      Else
        If V1>V2 Then Rez[k] := 1
        Else Rez[k] := 0;
    End;
  WriteLn(Fout, Cate);
  For k := 1 To N Do
    WriteLn(Fout, Rez[k]);
  Close(Fout);
End.
