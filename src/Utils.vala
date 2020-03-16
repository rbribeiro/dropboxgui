public class Utils : GLib.Object {
    public signal void glib_settings_changed;
    public GLib.Settings glib_settings;
    public Utils() {
        try {
            glib_settings = new GLib.Settings ("com.github.rbribeiro.dropboxgui");


        } catch (Error e) {

        }

    }
}
