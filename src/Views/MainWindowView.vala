public class MainWindow: Gtk.ApplicationWindow {
    public Gtk.Label status_label;
    public Gtk.Stack stack;
    public StatusBar status_bar;
    public Gtk.Button dropbox_folder_button;
    public Gtk.Button settings_button;

    public MainWindow (Gtk.Application app) {
        Object (
            application : app
        );
    }

    construct {
        var shareView = new ShareView();
        dropbox_folder_button = new Gtk.Button.from_icon_name("folder-symbolic");
        settings_button = new Gtk.Button.from_icon_name("open-menu-symbolic");

        var headerBar = new Gtk.HeaderBar ();
        headerBar.get_style_context ().add_class ("default-decoration");
        headerBar.get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
        headerBar.title = "Dropper";
        headerBar.show_close_button = true;
        headerBar.pack_end(settings_button);
        headerBar.pack_end(dropbox_folder_button);

        stack = new Gtk.Stack ();
        stack.transition_type = Gtk.StackTransitionType.SLIDE_LEFT_RIGHT;
        stack.add_titled (shareView, "share", "Share Public");

        status_bar = new StatusBar ();

        var box = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);
        box.margin = 12;
        box.pack_start(stack, true, true, 1);
        box.pack_end(status_bar, false, true, 0);
        add(box);
        get_style_context ().add_class ("default-decoration");
        resizable = false;
        set_titlebar(headerBar);
        get_style_context ().add_class ("rounded");
        set_default_size(250,320);
        window_position = Gtk.WindowPosition.MOUSE;
        set_icon_from_file("/home/rodrigo/Public/ValaCounter/data/imgs/Dropbox-icon.png");
        set_keep_above (true);

    }
}
