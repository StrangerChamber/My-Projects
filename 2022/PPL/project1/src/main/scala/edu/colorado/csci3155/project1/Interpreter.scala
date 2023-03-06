package edu.colorado.csci3155.project1


class RuntimeError(msg: String) extends Exception {
    override def toString(): String = {
        s"Error: $msg"
    }
}


object Interpreter {


    type Environment = Map[String, Value]



    /*--
        TODO: Complete the evalExpr Function below.
        Please write refactored code and use ValueOps.plus, ValueOps.minus,..
        defined in Value.scala for evaluating the expressions.

        If you encounter error, you should throw a RuntimeError exception defined above.
        Please do not use other exception types.
     */
    def evalExpr(e: Expr, env: Environment) : Value = ???

    /*--
    TODO: Implement a function evalVarDefine that given a identifier x,
    expression e and environment env,
       a) evaluates e under env: let result be v
       b) yields new environment that updates env with {x -> v }
     For your convenience the RuntimeError exception has been handled for you.
     */
    def evalVarDefine(x: String, e: Expr, env: Environment): Environment = {
        try {
            ??? // Your code here.
        } catch {
            case _:RuntimeError =>  env
        }
    }

    /*-- TODO: Complete the evalCommand Function Below --*/
    // Function evalCommand
    // Evaluate a command under an environment.
    //  Returns the new environment as a result of executing the command.
    //  If the command is of the form Define(x, e), the environment is updated by evaluating
    //  e under the "old" environment and updating the old environment to now bind x to the result.
    // If the command is of the form Display(e), the environment returned is just the
    // same as the environment that was passed in as an argument.
    //
    def evalCommand( env: Environment, cmd: Cmd): Environment = ???

    /*-- TODO: Implement evalProgram function below.
       Careful: Do not use for/while loops. Instead you should be using
       pattern matching on `prog` and then using lst foldLeft function.
       A tail recursive solution is also acceptable but please try to use pattern matching.
     */
    def evalProgram(prog: CalcProgram, env0: Environment = Map.empty): Environment = ???

}
