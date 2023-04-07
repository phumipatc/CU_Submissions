package lecture01_commonfeatures

object IfExpression {
  def main(args: Array[String]): Unit = {
    var age = 15
    var x = 3;
    var message = ""

    var result = if(age !=15) "age is not 15" else "age is 15"
    println(result)

  }
}
