program dpa_piata;
const fi='piata.in';
      fo='piata.out';
var f:text;
    n,iT,jT,iM,jM,i,j:longint;
    s,e1,e2,s1:longint;
    a:array[1..250,1..250]of byte;

function fu(k:longint):byte;
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
{linia 1}
for j:=1 to n do a[1,j]:=fu(j);
{liniile 2, 3, ..., n}
for i:=2 to n do
begin
 for j:=2 to n do
  a[i,j]:=a[i-1,j-1];
 a[i,1]:=a[i-1,n];
end;
s:=0;
for i:=iT to iM do
 for j:=jT to jM do
  s:=s+a[i,j];
assign(f,fo);rewrite(f);
writeln(f,s);
close(f);
end.