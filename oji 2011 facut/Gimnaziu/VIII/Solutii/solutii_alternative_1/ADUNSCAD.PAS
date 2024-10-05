{Serban Marinel- februarie 2011}
{utilizez operatorii pe biti - 100 puncte}
Program AdunScad;

Var Fin, Fout: Text;
    Cifre: Array[1..20] Of Integer;
    Operatori, Limita: LongInt;
    N, M, Caz: Integer;
    Gasit: Boolean;

Procedure Citire;
Var i: Integer;
Begin
  Assign(Fin, 'adunscad.in'); Reset(Fin);
  ReadLn(Fin, N, M);
  For i := 1 To M Do
    Read(Fin, Cifre[i]);
  Close(Fin);
End;

Function OK: Integer;
Var SP, SN: LongInt;
    i, j: Integer;
Begin
  SP := 0; SN := 0;
  For i := M-1 DownTo 0 Do
    If Operatori AND (1 SHL i) <> 0 Then
      Begin
        j := M - i;
        SP := SP - Cifre[j];
        SN := SN + Cifre[j]
      End
    Else
      Begin
        j := M - i;
        SP := SP + Cifre[j];
        SN := SN - Cifre[j]
      End;
  If SP = N Then OK := 1
  Else
    If SN = N Then OK := 2
    Else OK := 0;
End;

Procedure Afiseaza(Caz: Integer);
Var i: Integer;
Begin
  Assign(Fout, 'adunscad.out'); ReWrite(Fout);
  If Caz = 1 Then
    Begin
      If Operatori AND (1 SHL (M-1)) <> 0 Then
        Write(Fout, '-');
      For i := 1 To M-1 Do
        Begin
          Write(Fout, Cifre[i]);
          If Operatori AND (1 SHL (M-i-1)) <> 0 Then
            Write(Fout, '-')
          Else
            Write(Fout, '+')
        End;
      WriteLn(Fout, Cifre[M])
    End
  Else
    Begin
      If Operatori AND (1 SHL (M-1)) = 0 Then
        Write(Fout, '-');
      For i := 1 To M-1 Do
        Begin
          Write(Fout, Cifre[i]);
          If Operatori AND (1 SHL (M-i-1)) <> 0 Then
            Write(Fout, '+')
          Else
            Write(Fout, '-')
        End;
      WriteLn(Fout, Cifre[M])
    End;
  Close(Fout)
End;

Begin
  Citire;
  Gasit := FALSE;
  Operatori := 0;  {toti +}
  Limita := 1 SHL (M-1);
  While (NOT Gasit) AND (Operatori < Limita) Do
    Begin
      Caz := OK;
      If Caz <> 0 Then
        Begin
          Afiseaza(Caz);
          Gasit := TRUE
        End;
      Inc(Operatori)
    End;
  If NOT Gasit Then
    Begin
      Assign(Fout, 'adunscad.out'); ReWrite(Fout);
      WriteLn(Fout, 0);
      Close(Fout)
    End;
End.
