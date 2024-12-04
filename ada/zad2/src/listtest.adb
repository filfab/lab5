with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Strings.Unbounded; use  Ada.Strings.Unbounded;
with Ada.Strings.Unbounded.Text_IO; use Ada.Strings.Unbounded.Text_IO;
with Ada.Strings.Fixed; use Ada.Strings.Fixed;
with List;

procedure ListTest is
   --  type Pair is record
   --     a : Integer := 0;
   --     b : Integer := 0;
   --  end record;

   --  procedure Init (X : out Pair) is
   --     a : Integer;
   --     b : Integer;
   --  begin
   --     Put("<< First value: ");
   --     Get(a);
   --     Put("<< Second value: ");
   --     Get(b);
   --     Skip_Line;
   --     X.a := a;
   --     X.b := b;
   --  end Init;
   --  function Repr (X : Pair) return String is
   --  begin
   --     return "("&Trim(X.a'Image, Ada.Strings.Left)&";"&Trim(X.b'Image, Ada.Strings.Left)&")";
   --  end Repr;
   --  package PairListLib is new List (T => Pair, ReprElem => Repr); use PairListLib;
   --  subtype PairList is PairListLib.ListType;

   procedure Init (X : out Integer) is
      value : Integer;
   begin
      Put("<< Value: ");
      Get(value);
      Skip_Line;
      X := value;
   end Init;
   function Repr (X : Integer) return String is
   begin
      return Trim(X'Image, Ada.Strings.Left);
   end Repr;
   package IntegerListLib is new List (T => Integer, ReprElem => Repr); use IntegerListLib;
   subtype IntegerList is IntegerListLib.ListType;

   list : IntegerList;
   elem : Integer;

   continue : Boolean := True;
   command : Unbounded_String;
   index : Integer;
begin
   while continue loop
      Put("<< Command: ");
      Get_Line(command);

      if command = "pop" then
         if not IsEmpty(list) then
            Put_Line(">> Result: " & Repr(Pop(list)));
         else
            Put_Line("Err - List is empty!");
         end if;

      elsif command = "push" then
         Init(elem);
         Push(list, elem);
         Put_Line(">> OK");

      elsif command = "append" then
         Init(elem);
         Append(list, elem);
         Put_Line(">> OK");
         
      elsif command = "print" then
         Put("<< ");
         Print(list);

      elsif command = "get" then
         Put("<< Index: ");
         Get(index);
         Skip_Line;
         if (index > 0 and index <= Length(list))
         or (index < 0 and index >= -Length(list)) then
            Put_Line(">> Result: " & Repr(Get(list, index)));
         else
            Put_Line("Err - Bad index!");
         end if;

      elsif command = "put" then
         Put("<< Index: ");
         Get(index);
         Skip_Line;
         if (index > 0 and index <= Length(list))
         or (index < 0 and index >= -Length(list)) then
            Init(elem);
            Put(list, index, elem);
            Put_Line(">> OK");
         else
            Put_Line("Err - Bad index!");
         end if;

      elsif command = "insert" then
         Put("<< Index: ");
         Get(index);
         Skip_Line;
         if index >= 1 and index <= Length(list)+1 then
            Init(elem);
            Insert(list, index, elem);
            Put_Line(">> OK");
         else
            Put_Line("Err - Bad index!");
         end if;

      elsif command = "delete" then
         Put("<< Index: ");
         Get(index);
         Skip_Line;
         if (index > 0 and index <= Length(list))
         or (index < 0 and index >= -Length(list)) then
            Delete(list, index);
            Put_Line(">> OK");
         else
            Put_Line("Err - Bad index!");
         end if;

      elsif command = "clean" then
         Clean(list);
         Put_Line(">> List cleaned");

      elsif command = "length" then
         Put_Line(">> Length:" & Length(list)'Image);

      elsif command = "exit" then
         continue := False;
      elsif command = "test" then
         Clean(list);
         for j in 1..5 loop
            Append(list, j);
         end loop;
         Print(list);

      else
         Put_Line("Err - Unknown command!");
      end if;
   end loop;
   Clean(list);
end ListTest;