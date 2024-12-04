with Ada.Unchecked_Deallocation;

generic
   type T is private;
   with function ReprElem (X : T) return String;
package List is
   type ListType is private;

   function IsEmpty (l : ListType) return Boolean;

   function Pop (l : in out ListType) return T;
   procedure Push (l : in out ListType; e : T);
   procedure Append (l : in out ListType; e : T);

   function Get (l : ListType; i : Integer) return T;
   procedure Put (l : in out ListType; i : Integer; e : T);
   procedure Insert (l : in out ListType; i : Integer; e : T);
   procedure Delete (l : in out ListType; i : Integer);

   procedure Print (l : ListType);
   procedure Clean (l : in out ListType);
   function Length (l : ListType) return Integer;
private

   type Node;
   type NodePtr is access Node;
   type Node is record
      elem : T;
      next : NodePtr := null;
   end record;

   type ListType is record
      first : NodePtr := null;
      last : NodePtr := null;
      length : Integer := 0;
   end record;

   function Find (l : ListType; i : Integer) return NodePtr;

   procedure Free is new Standard.Ada.Unchecked_Deallocation (Node, NodePtr);
end List;
