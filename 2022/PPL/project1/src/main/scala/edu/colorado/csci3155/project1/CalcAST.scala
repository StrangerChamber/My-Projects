package edu.colorado.csci3155.project1

/*--
  TODO : Implement the inductive definition for the abstract syntax of our
    programming language here.
    Important: follow the grammar in the notes precisely or else, things will not
    work.
 ---*/

sealed trait CalcProgram
case class TopLevel(listOfCmds: List[Cmd]) extends CalcProgram
sealed trait Cmd
sealed trait Expr
// .. The rest of the definitions below ...