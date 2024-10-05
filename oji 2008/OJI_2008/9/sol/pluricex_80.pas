{Marinel Serban; pentru 80 puncte}
Program PluriCEX;
Var n, k, D, i, j, s, s1: Integer;
    P: Array[1..30, 0..30] Of Integer;
    Fin, Fout: Text;
    v: Array[0..30] Of Boolean;
    disc: Array[1..10] Of Integer;
Begin
  Assign(Fin, 'pluricex.in'); Reset(Fin);
  Read(Fin, n, k, D);
  For i := 1 To n Do
    Begin
      Read(Fin, P[i][0]);
      For j := 1 To P[i][0] Do
        Read(Fin, P[i][j]);
    End;
  Assign(Fout, 'pluricex.out'); ReWrite(Fout);
  For i := 0 To n Do v[i] := TRUE;
  While v[0] Do
    Begin
      s := 0;
      For i := 1 To n Do Inc(s, Ord(v[i]));
      For i := 1 To 10 Do disc[i] := 0;
      For i := 1 To n Do
        If v[i] Then
          For j := 1 To P[i][0] Do
            disc[P[i][j]] := 1;
      s1 := 0;
      For i := 1 To 10 Do Inc(s1, disc[i]);
      If (s=k) AND (s1=D) Then
        Begin
          For i := 1 To n Do
            If v[i] Then Write(Fout, i, ' ');
          WriteLn(Fout)
        End;
      i := n;
      While NOT v[i] Do
        Begin
          v[i] := TRUE;
          Dec(i)
        End;
      v[i] := FALSE
    End;
  Close(Fout);
End.

