

public class ValaCounter : Gtk.Application {
    public ValaCounter() {
        Object(
            application_id : "com.github.rbribeiro.dropboxgui",
            flags: ApplicationFlags.FLAGS_NONE
        );
    }
    private MainWindow main_window;
    private Unity.LauncherEntry udock;

    public void notify() {
        var noti = new Notification("oi");
        noti.set_body ("teste");
        this.send_notification("com.valacounterapp", noti);

    }

    private void open_settings () {
        var settings_window = new SettingsWindow ();
        settings_window.show_all();
    }

    private void open_dropbox_folder () {
        try {
            AppInfo.launch_default_for_uri ("file:///home/rodrigo/Dropbox", null);
        } catch (GLib.Error e) {
            print(e.message);
        }

    }
    
    private bool on_close () {
        var utils = new Utils ();
        int x, y;
        main_window.get_position (out x, out y);
        utils.glib_settings.set_int ("window-pos-x", x);
        utils.glib_settings.set_int ("window-pos-y", y);
        
        return false;
    }

    private void on_dropbox_status_change (string[] args) {

        if(args[0] == "Uploading" || args[0] == "Indexing" || args[0] == "Syncing" || args[0] == "Downloading") {
            udock.progress_visible = true;
            udock.progress = double.parse(args[2]);
            udock.urgent = false;
        } else if (args[0] == "Up") {

            udock.progress_visible = false;
            udock.urgent = false;
        } else {
            udock.progress_visible = false;
            udock.urgent = true;

        }

        main_window.status_bar.new_status(args[0], args[1]);
    }


    protected override void activate() {
        udock = Unity.LauncherEntry.get_for_desktop_id("com.github.rbribeiro.dropboxgui.desktop");

        var dropbox = new Dropbox ();
        dropbox.timeout (1000);
        dropbox.status_changed.connect ( on_dropbox_status_change);

        main_window = new MainWindow (this);
        main_window.dropbox_folder_button.clicked.connect(open_dropbox_folder);
        main_window.settings_button.clicked.connect (open_settings);
        main_window.show_all();

        add_window (main_window);
        
        main_window.delete_event.connect ( on_close);

    }

    public static int main(string[] args) {
        var app = new ValaCounter ();
        return app.run (args);
    }
}
