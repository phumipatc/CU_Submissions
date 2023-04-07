package lecture01_commonfeatures

object FunctionDefaultArg {
  object Math {
    def addM(x:Int =1,y:Int =1):Int = x+y
    def squareM(x:Int = 1):Int = x*x
  }

  def main(args: Array[String]): Unit = {
    println(Math.addM(5))
    println(Math.squareM())
  }
}
