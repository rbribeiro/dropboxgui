public class StatusBar : Gtk.Grid {

    construct {

        orientation = Gtk.Orientation.HORIZONTAL;

        status = new Gtk.Label("Checking Dropbox...");
        status.single_line_mode = true;
        status.lines = 0;
        status.ellipsize = Pango.EllipsizeMode.END;
        status.use_markup = true;
        status.max_width_chars = 25;
        status.set_valign (Gtk.Align.BASELINE);
        status.wrap = true;

        status_img = new Gtk.Image.from_icon_name ("emblem-synchronized",Gtk.IconSize.SMALL_TOOLBAR);
        status_img.margin = 4;
        add(status_img);
        add(status);
        
    }

    public Gtk.Label status {get; set;}
    public Gtk.Image status_img {get; set;}

    public void new_status(string action, string status_text) {

        status.label = status_text;
        if(action == "Up") {
               status_img.icon_name = "process-completed";
             } else if (action == "Dropbox") {
                   status_img.icon_name = "process-stop";
                } else {
                     status_img.icon_name = "emblem-synchronized";
                }
    }

}
