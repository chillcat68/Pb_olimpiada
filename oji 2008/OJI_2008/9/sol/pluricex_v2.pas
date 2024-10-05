{Constantin Galatan, 100 puncte}
const DIM = 31;
type SIR = array[1..DIM] of integer;
     MAT = array[1..DIM, 1..DIM] of integer;
var  x, s : SIR;
     di   : MAT;
     n, k, D: integer;
     fout : text;

procedure Citeste;
var fin : text;
    i, j, nrdisc, disc : integer;
begin
     assign(fin, 'pluricex.in');
     reset(fin);
     readln(fin, n, k, D);
     for i := 1 to n do
     begin
          read(fin, nrdisc);
          for j := 1 to nrdisc do
          begin
               read(fin, disc);
               di[i,disc] := 1;
          end
      end;
  	close(fin);
end;

procedure Afiseaza(k : integer);
var i : integer;
begin
   for i := 1 to k do
      write(fout, x[i], ' ');
   writeln(fout)
end;

function Cond : boolean;
var i, j : integer;
    sel : boolean;
begin
   for i := 1 to D do  s[i] := 0;
   for i := 1 to k do
       for j := 1 to D do
           if di[x[i], j] = 1 then s[j] := 1;
   i := 1;  sel := true;
   while (i <= D) and sel do
      begin
         if (s[i] = 0 ) then sel := false;
         inc(i)
      end;
   Cond := sel
end;

procedure Echipe;
var i: integer;
    ok : boolean;
begin
	i := 1;
	while i > 0 do
       begin
	      ok := false;
		  if x[i] < n - k + i then
             begin
	            inc(x[i]); ok := true;
             end;
          if (ok) then
			if  i = k then begin if Cond then  Afiseaza(i); end
			else
               begin
                  inc(i); x[i] := x[i-1];
               end
		else dec(i);
       end
end;

begin {main}
   Citeste;
   assign(fout, 'pluricex.out');
   rewrite(fout);
   Echipe;
   close(fout);
end.



