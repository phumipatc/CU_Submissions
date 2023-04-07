package lecture01_commonfeatures

object MatchExpression {
  def main(args: Array[String]): Unit = {
    var x = 25
    var res = x match {
      case 10 => 10.0
      case 20 => 20.0
      case 25 => {
        x = 33
        25.0
      }
      case 30 => 30.0
      case _ =>
    }
    println(res)
    println(x)
  }
}
