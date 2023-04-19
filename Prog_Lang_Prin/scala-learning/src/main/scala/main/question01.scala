package main

object question01 {
  def process(x: Any, pos: Int, l: List[Any]) : List[Any] = {
    if(l.length == pos)
      return x::l
    return l.head::process(x,pos,l.tail)

  }
  def insertATPosition(x:Any, pos: Int, l:List[Any]) : List[Any] = {
    var len = l.length-pos
    return process(x,len,l)
  }
  def main(args: Array[String]) : Unit = {
    var l = List(0,1,2,3,4,5,6,7,8,9)
    println(insertATPosition(100,5,l))
  }
}
