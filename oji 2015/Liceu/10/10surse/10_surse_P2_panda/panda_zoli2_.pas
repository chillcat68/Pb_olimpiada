{
	Sursa 100p
	prof. Zoltan Szabo
	isj Mures
}
var f,g:text;
    a,b:array[1..500,1..500] of longint;
    coada:array[0..2,0..250000] of longint;
    timp, nr, prim, ultim, ultim1, i,j,l,c,k,x,y,p,n,m,t,acces,lin, col, cheie, timpmin,s:longint;
    gata,ok:boolean;

procedure push (l,c:integer);
begin
  inc(ultim);
  coada[0][ultim]:=l;
  coada[1][ultim]:=c;
  coada[2][ultim]:=timp+1;
  if b[l][c]=1 then
    begin
      gata:=true;
      inc(nr);
    end;
  b[l][c]:=2;
end;

begin
  assign(f,'panda.in');
  assign(g,'panda.out');
  reset(f);
  rewrite(g);
  readln(f,p,n,m,t,l,c,k,s);
  for i:=1 to t do
    begin
      readln(f,x,y);
      b[x,y]:=1;
    end;
  cheie:=1;
  for i:=1 to s do
    cheie:=cheie*2;

  acces:=0;
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(f,x);
        a[i][j]:=ord(((x mod cheie) xor (k mod cheie)) = cheie-1);
        acces:=acces+a[i][j];
      end;

  if (p=1) then
    writeln(g,acces-1)
  else
    begin
      coada[0][0]:=l;
      coada[1][0]:=c;
      coada[2][0]:=0;
      prim:=0;
      ultim:=0;
      gata:=false;
      timpmin:=30000;
      ok:=false;
      b[l][c]:=2;
      nr:=0;
      while not gata do
        begin
          ultim1:=ultim;
          for i:=prim to ultim1 do
            begin
              lin:=coada[0][i];
              col:=coada[1][i];
              timp:= coada[2][i];
              if (col>1) and (a[lin][col-1]=1) and (b[lin][col-1]<>2) then
                push(lin,col-1);
              if (col<m) and (a[lin][col+1]=1) and (b[lin][col+1]<>2) then
                push(lin,col+1);
              if (lin>1) and (a[lin-1][col]=1) and (b[lin-1][col]<>2) then
                push(lin-1,col);
              if (lin<n) and (a[lin+1][col]=1) and (b[lin+1][col]<>2) then
                push(lin+1,col);
            end;
          prim:=ultim1+1;
        end;
      writeln(g,timp+1,' ',nr);
    end;
  close(f);
  close(g);
end.
