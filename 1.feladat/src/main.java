public class main {
    public static void main(String[] args) {

        //INPUT
        String Input = "{1}(5)∗:=<>p$";
        //input kiírás
        for (int i = 0; i < Input.length(); i++) {
            System.out.println(Input.charAt(i));
        }
        allapotok feladat = new allapotok(Input);
        feladat.allapot1();
    }
}