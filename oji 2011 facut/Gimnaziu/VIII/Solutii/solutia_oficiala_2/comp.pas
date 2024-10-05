{Nodea Eugen - 100 puncte}
type vect= array[1..1001] of boolean;
var
   f          : text;
   i,n,k,semn : integer;
   sol        : vect;
   e          : string;
   es,ed      : longint;
   p          : byte;
Function numar(t:string) : longint;
var x,y : longint;
      i : byte;
begin
    i := 1; x := 0;
    while ( i <= length(t) ) do
    begin
        y:=0;
        while (t[i] in ['0'..'9']) do
        begin
            y := y*10 + ord(t[i]) - 48;
            inc(i);;
        end;
        case t[i] of
        'm': x := x + 1000 * y;
        's': x := x + 100 * y;
        'z': x := x + 10 * y;
        'u': x := x + 1 * y;
        end;
        inc(i);
    end;
    numar := x;
end;
Function eval(s:string) : longint;
var  sol : longint;
     p   : byte;
     t   : string;
begin
      sol := 0;
      repeat
             p := pos('+', s);
             if (p>0) then begin
                                t := copy(s,1,p-1);
                                delete(s,1,p);
                           end
                      else t := s;
             sol := sol + numar(t);
      until p = 0;
      eval := sol;
end;
Begin

    assign (f, 'comp.in'); reset (f);
    readln (f, n);
    for i := 1 to n do
    begin
        readln (f,e);
        semn := -1;
        p := pos('<', e);
        if (p > 0) then begin inc(k); semn := 1; end
           else  p := pos('>', e);
        {extragem partea stanga a expresiei si partea dreapta}
        es := eval( copy(e, 1, p-1));
        ed := eval( copy(e, p+1, length(e)-p ));
        sol[i] := es*semn < ed*semn;
    end;
    close (f);
    assign (f,'comp.out'); rewrite (f);
    writeln (f, k);
    for i := 1 to n  do
        writeln(f, ord(sol[i]),' ');
    close (f);
End.
