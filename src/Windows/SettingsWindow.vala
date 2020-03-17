public class SettingsWindow : Gtk.Window {
    public SettingsWindow () {

        var headerBar = new Gtk.HeaderBar ();
        headerBar.get_style_context ().add_class ("default-decoration");
        headerBar.title = "Dropbox GUI Settings";
        headerBar.show_close_button = true;

        var panel = new SettingsView ();
        add (panel);
        set_titlebar (headerBar);
        set_default_size (500,500);
        window_position = Gtk.WindowPosition.CENTER;
    }
}
