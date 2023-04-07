package lecture01_commonfeatures

object Function {
  object Math {
    def *(x:Int,y:Int):Int = x+y
    def squareM(x:Int):Int = x*x
  }

  def main(args: Array[String]): Unit = {
      println(Function.area(2,3))
      println(areaScale(4,5))
      println(Math.*(5,3))  //function of object Math
      println(Math squareM 3)  //one argument function call
      println(5*3)
  }

  def area(width: Int, height: Int): Int = {
    width * height
  }
  def areaScale(w: Int, h: Int): Int ={
    val w2 = w+1   // w += 1 is not allowed
    val h2 = h+1
    w2*h2  //last statement will be returned (you can use "return")
  }
}
