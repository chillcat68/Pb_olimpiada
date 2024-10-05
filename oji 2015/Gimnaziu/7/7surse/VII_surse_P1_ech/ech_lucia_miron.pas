{Lucia Miron}
program ech;
var n,r:integer;
v:array[0..100]of integer;
fin,fout:text;
procedure citire;
var i,aux:integer;
    ch:char;
begin
    assign(fin,'ech.in'); reset(fin);
    while(not seekeoln(fin)) do
        begin
         read(fin,ch);
         inc(n);
         v[n]:=ord(ch)-ord('0');
        end;
    v[0]:=n;
    for i:=1 to n div 2 do
        begin
        aux:=v[i];v[i]:=v[n+1-i];v[n+1-i]:=aux;
        end;
end;
procedure aduna(r:integer);
var i,t,aux:integer;
begin
        t:=r;
        for i:=1 to v[0] do
         begin
          aux:=v[i]+t;
          v[i]:=aux mod 10;
          t:=aux div 10;
         end;
         if t<>0 then
                begin
                 inc(v[0]);
                 v[v[0]]:=t;
                end;
end;
function ech:boolean;
var i,sp,si:integer;
begin
 sp:=0;si:=0;
 for i:=1 to v[0] do
  if i mod 2=1 then si:=si+v[i]
  else sp:=sp+v[i];
  if si= sp then ech:=true
  else ech:=false;
end;
function rest:integer;
var i,r:integer;
begin
 r:=0;
 for i:=v[0] downto 1 do
  r:=(r*10+v[i]) mod 11;
 rest:=r;
end;
procedure afis;
var i:integer;
begin
assign(fout,'ech.out'); rewrite(fout);
for i:=v[0] downto 1 do
   write(fout,v[i]);
writeln(fout);
end;
begin{pp}
citire;
r:=rest;
if(r>0) then aduna(11-r)
else aduna(11);
while(not ech) do aduna(11);
afis;
close(fout);
end.











