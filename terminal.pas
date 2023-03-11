{ GPIO Terminal for Arduino Connection on 0x20
  By Eightbitswide

  Terminal setup for local echo.

  Keyboard input ccode by David Collins
}


var key,clk,datain:integer;
label Terminal;

function Inkey:integer;
begin
  if bios(1)=255 then inkey:=bios(2) else inkey :=0;
end;


begin;
WriteLn('Terminal Active: [ESC] to Exit:');
Terminal:

clk:=clk+1;

if clk = 200 then begin
  port[1]:=130;
  datain:=port[0];
  if datain = 255 then datain:=0;
  if datain > 13 then write(chr(datain));
  if datain = 13 then writeln('');
  clk:=0;
  end;

key:=Inkey;

if key = 27 then halt;
if key = 13 then writeln('');

if key > 0 then begin
 write(char(key));
 port[1]:=3;
 port[0]:=key;
 key:=0;
end;


goto Terminal;
end.

