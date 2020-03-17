public class Utils : GLib.Object {
    public signal void glib_settings_changed (string key);
    public GLib.Settings glib_settings;
    public Utils() {
        glib_settings = new GLib.Settings ("com.github.rbribeiro.dropboxgui");
        glib_settings.changed.connect ( key => {
            glib_settings_changed (key);
        });

    }
}
