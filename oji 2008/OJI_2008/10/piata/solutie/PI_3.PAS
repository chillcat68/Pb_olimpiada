program dpa_piata;
const fi='piata.in';
      fo='piata.out';
var f:text;
    n,iT,jT,iM,jM,i,j:longint;
    s:longint;
    v,v1:array[1..28002]of byte;

function fu(k:longint):byte;
var s:byte;
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
s:=0;
for j:=1 to n do v1[j]:=fu(j);
if iT=1 then
 for j:=jT to jM do s:=s+v1[j];
{liniile 2, 3, ..., n}
for i:=2 to n do
begin
 for j:=2 to n do
  v[j]:=v1[j-1];
 v[1]:=v1[n];
 v1:=v;
 if (iT<=i)and(i<=iM) then
  for j:=jT to jM do s:=s+v1[j];
end;
assign(f,fo);rewrite(f);
writeln(f,s);
close(f);
end.