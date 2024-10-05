program dpa_piata;
const fi='piata.in';
      fo='piata.out';
var f:text;
    n,iT,jT,iM,jM,i,j:longint;
    s,e1,e2,s1:longint;

function fu(k:longint):longint;
var s:longint;
begin
 s:=0;
 while k>0 do
  begin
   s:=s+(k mod 10);
   k:=k div 10;
  end;
 fu:=s;
end;

begin
assign(f,fi);reset(f);
readln(f,n);
readln(f,iT,jT);
readln(f,iM,jM);
close(f);
{suma de pe linia iT}
s:=0;
for j:=jT to jM do
 if j>=iT then s:=s+fu(j-iT+1)
          else s:=s+fu(n+j-iT+1);
{sumele de pe liniile iT+1, iT+2, ..., iM}
s1:=s;{suma de pe linia anterioara}
for i:=iT+1 to iM do
 begin
  {elementul de pe linia i, coloana jM}
  if jM>=i-1 then e1:=fu(jM-(i-1)+1) else e1:= fu(n+jM-(i-1)+1);
  {elementul de pe linia i, coloana jT}
  if jT>=i then e2:=fu(jT-i+1) else e2:= fu(n+jT-i+1);
  s:=s+s1-e1+e2;
  s1:=s1-e1+e2;
 end;
assign(f,fo);rewrite(f);
writeln(f,s);
close(f);
{for i:=1 to n do
 begin
  for j:=1 to n do
   if j>=i then write(fu(j-i+1),' ') else write(fu(n+j-i+1),' ');
  writeln;
 end; }
end.