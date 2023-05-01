package main

object Question09 {
  def turingStep(f:Char => Char,tape:List[Char], n:Int): List[Char] = {
    if(tape.isEmpty)
      return tape
    if(n>0)
      return f(tape.head)::turingStep(f, tape.tail, n-1)
    return tape
  }
  def main(args:Array[String]): Unit = {
    var tape = List('C', 'H', 'A', 'R')
    var f1 = (x:Char) => x.toLower
    println(turingStep(f1,tape,2))
    println(turingStep(f1,tape,3))
    println(turingStep(f1,tape,0))
    println(turingStep(f1,tape,5))
  }
}
