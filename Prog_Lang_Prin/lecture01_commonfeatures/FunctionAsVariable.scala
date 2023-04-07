package lecture01_commonfeatures

object FunctionAsVariable {
  def main(args: Array[String]): Unit = {
    var x = (a:Int, b:Int) => a+b
    var z = (a:Int, b:Int) => {
      var c = a+b
      c*c
    }
    println(x(5,7))
    println(z(2,3))
  }
}
