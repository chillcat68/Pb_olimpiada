Program Covor_FPascal;
{Marinel Serban februarie 2015}

Var fin, fout: text;
    n, k, p, S, Vp, r, patrat, caz: longint;
    gasit: Boolean;
Begin
  Assign(fin, 'covor.in'); Reset(fin);
  Assign(fout, 'covor.out'); ReWrite(fout);
  ReadLn(fin, n, k);
  ReadLn(fin, caz);
  {punctul a) si precalcul pentru b)}
  S := 1; p := 1;
  Vp := 1; r := 2; {patrate partea superioara}
  gasit := false;
  While (S + 4 * p - 1 <= n) Do
  Begin
    S := S + 4 * p - 1;
    If (NOT gasit) Then  {daca nu am gasit inca patratul}
      Begin
        Vp := Vp + r;    {varful de la mijloc creste cu r}
        r := r + 2;      {r creste cu 2}
        If (k <= Vp) Then     {am gasit patratul}
          Begin
            gasit := true;
            patrat := p;
          End;
      End;
    Inc(p);              {patrat in sus}
  End;
  Dec(p);
  If (caz = 1) Then
    WriteLn(fout, p);
  {caz b) in continuare}
  If (NOT gasit) Then    {k poate fi in cealalta parte}
    Begin
      Vp := Vp + p;
      r := r - 2;
      While ((NOT gasit) AND (p >= 1)) Do
        Begin
          If (k < Vp + p) Then
            Begin
              gasit := true;
              patrat := p;
              break;
            End;
          Dec(p);
          r := r - 2;
          Vp := Vp + r;
        End;
    End;
    If (caz = 2) Then
      WriteLn(fout, patrat);
  Close(fin);
  Close(fout);
End.
