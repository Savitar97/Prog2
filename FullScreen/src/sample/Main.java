package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;


import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.Stage;
import java.io.File;
import java.io.IOException;


public class Main extends Application {

    @Override public void start(Stage primaryStage) throws IOException {

        // Image
        Image img = new Image("pic1.png",1260,600,false,true);
        Image img1 = new Image("pic2.png",1260,600,false,true);
        ImageView iv=new ImageView(img);
        HBox hbox1=new HBox(8);
        hbox1.getChildren().add(iv);


        //Title
        primaryStage.setTitle("FullScreen");

        //Text
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("ERROR");
        alert.setHeaderText(null);
        alert.setContentText("Ohhh nooo! You hacked the NASA!");






        // Button
        Button Start = new Button("Start");
        Start.setStyle("-fx-background-color:\n"
                + "        #090a0c,\n"
                + "        linear-gradient(#38424b 0%, #1f2429 20%, #191d22 100%),\n"
                + "        linear-gradient(#20262b, #191d22),\n"
                + "        radial-gradient(center 50% 0%, radius 100%, rgba(114,131,148,0.9), rgba(255,255,255,0));\n"
                + "    -fx-background-radius: 5,4,3,5;\n"
                + "    -fx-background-insets: 0,1,2,0;\n"
                + "    -fx-text-fill: white;\n"
                + "    -fx-effect: dropshadow( three-pass-box , rgba(0,0,0,0.6) , 5, 0.0 , 0 , 1 );\n"
                + "    -fx-font-family: \"Arial\";\n"
                + "    -fx-text-fill: linear-gradient(white, #d0d0d0);\n"
                + "    -fx-font-size: 12px;\n"
                + "    -fx-padding: 10 20 10 20;");
        Button Fullscreen=new Button("FullScreen");
        Fullscreen.setStyle("-fx-background-color:\n"
                + "        #090a0c,\n"
                + "        linear-gradient(#38424b 0%, #1f2429 20%, #191d22 100%),\n"
                + "        linear-gradient(#20262b, #191d22),\n"
                + "        radial-gradient(center 50% 0%, radius 100%, rgba(114,131,148,0.9), rgba(255,255,255,0));\n"
                + "    -fx-background-radius: 5,4,3,5;\n"
                + "    -fx-background-insets: 0,1,2,0;\n"
                + "    -fx-text-fill: white;\n"
                + "    -fx-effect: dropshadow( three-pass-box , rgba(0,0,0,0.6) , 5, 0.0 , 0 , 1 );\n"
                + "    -fx-font-family: \"Arial\";\n"
                + "    -fx-text-fill: linear-gradient(white, #d0d0d0);\n"
                + "    -fx-font-size: 12px;\n"
                + "    -fx-padding: 10 20 10 20;");

        Button Normalscreen=new Button("NormalScreen");
        Normalscreen.setStyle("-fx-background-color:\n"
                + "        #090a0c,\n"
                + "        linear-gradient(#38424b 0%, #1f2429 20%, #191d22 100%),\n"
                + "        linear-gradient(#20262b, #191d22),\n"
                + "        radial-gradient(center 50% 0%, radius 100%, rgba(114,131,148,0.9), rgba(255,255,255,0));\n"
                + "    -fx-background-radius: 5,4,3,5;\n"
                + "    -fx-background-insets: 0,1,2,0;\n"
                + "    -fx-text-fill: white;\n"
                + "    -fx-effect: dropshadow( three-pass-box , rgba(0,0,0,0.6) , 5, 0.0 , 0 , 1 );\n"
                + "    -fx-font-family: \"Arial\";\n"
                + "    -fx-text-fill: linear-gradient(white, #d0d0d0);\n"
                + "    -fx-font-size: 12px;\n"
                + "    -fx-padding: 10 20 10 20;");

        // Buttons layout
        HBox hbox = new HBox(8); // spacing = 8
        hbox.setStyle("-fx-padding: 15; -fx-font-size: 15pt;");
        hbox.getChildren().addAll(Start,Fullscreen,Normalscreen);
        hbox.setAlignment(Pos.BASELINE_CENTER);

        BorderPane bp = new BorderPane();
        bp.setStyle("-fx-background-color: linear-gradient(#ffffff,#f3f3f4);\n"
                + "    -fx-border-width: 1 1 1 1;\n"
                + "    -fx-border-color: #b4b4b4 transparent #b4b4b4 transparent;\n"
                + "    -fx-font-size: 1.083333em;\n"
                + "    -fx-text-fill: #292929;");

        bp.setPadding(new Insets(10, 20, 10, 20));
        bp.setTop(hbox1);
        bp.setRight(null);
        bp.setBottom(hbox);


        Start.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
                counter++;
                //Music
                Media media=new Media(new File("/home/nemesis/IdeaProjects/FullScreen/src/supa.mp3").toURI().toString());
                MediaPlayer player = new MediaPlayer(media);
                if(counter%2==0) {
                    iv.setImage(img1);
                    player.play();
                    alert.showAndWait();

                }
                else {
                    iv.setImage(img);
                }

            }
        });
        Fullscreen.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                primaryStage.setFullScreen(true);
            }
        });

        Normalscreen.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {
                primaryStage.setFullScreen(false);
            }
        });
        Scene scene = new Scene(bp, 500, 500);
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    static int counter=1;
    public static void main(String[] args) {
        Application.launch(args);
    }
}