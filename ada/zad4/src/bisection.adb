with Ada.Text_IO; use Ada.Text_IO;
with Ada.Long_Float_Text_IO; use Ada.Long_Float_Text_IO;
with Ada.Numerics.Long_Elementary_Functions; use Ada.Numerics.Long_Elementary_Functions;
with Ada.Exceptions;  use Ada.Exceptions;

procedure Bisection is
   function Func (X : Long_Float) return Long_Float is
   begin
      return Cos(X/2.0);
   end Func;

   type FuncType is access function (X : Long_Float) return Long_Float;
   BoundsError : exception;

   function FindZero (f : FuncType; a, b, eps : Long_Float) return Long_Float is
      aa : Long_Float := a;
      bb : Long_Float := b;
      x, y, h : Long_Float;
   begin
      if a >= b then raise BoundsError with "Given arguments don't make a range [ a>=b ]"; end if;
      x := f(a); y := f(b);
      if (x<0.0 and y<0.0) or (x>0.0 and y>0.0) then raise BoundsError with "Same sign in range ends [ f(a)*f(b) > 0 ]"; end if;

      loop
         x := (aa+bb)/2.0;
         y := f(x);
         h := (bb-aa)/2.0;
         if y = 0.0 or (h<eps and h>-eps) then exit; end if;

         h := f(aa);
         if (y<0.0 and h<0.0) or (y>0.0 and h>0.0) then
            aa := x;
         else
            bb := x;
         end if;
      end loop;
      return x;
   end FindZero;

   epsilon : Long_Float := 1.0;
begin
   for i in reverse -8..-1 loop
      epsilon := epsilon * 0.1;
      Put("10^" & i'Image & " :");
      Put(FindZero(Func'Access, 2.0, 4.0, epsilon), Aft => -i ,Exp => 0);
      Put_Line("");
   end loop;
exception
   when E : BoundsError => Put_Line(Exception_Message(E)); 
end Bisection;