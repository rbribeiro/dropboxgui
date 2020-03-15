public class FavView : Gtk.Box {
    private const Gtk.TargetEntry[] targets = {   {"text/uri-list",0,0}};
    private Gtk.IconView icon_view;
    private Gtk.ListStore list;
    public FavView() {
        halign = valign = Gtk.Orientation.CENTER;
        
        Gtk.IconTheme icon_theme = Gtk.IconTheme.get_default ();
        
        list = new Gtk.ListStore (2, typeof (Gdk.Pixbuf), typeof (string));
        Gtk.TreeIter iter;
        list.append(out iter);
        list.set(iter, 0, icon_theme.load_icon("folder", 24, 0), 1, "Folder");

        icon_view = new Gtk.IconView.with_model (list);
        icon_view.set_pixbuf_column (0);
        icon_view.set_text_column (1);
        icon_view.item_orientation = Gtk.Orientation.HORIZONTAL;
        icon_view.model = list;
        icon_view.spacing = 12;
        icon_view.enable_model_drag_dest (targets, Gdk.DragAction.COPY );
        //Gtk.drag_dest_set(this, Gtk.DestDefaults.ALL, targets, Gdk.DragAction.COPY);

        icon_view.drag_data_received.connect(on_drag_data_received);
        
        add (icon_view);
    }

    private void on_drag_data_received (Gtk.Widget widget, Gdk.DragContext context, int x, int y, Gtk.SelectionData data, uint info, uint time) {
        var file = GLib.File.new_for_uri(data.get_uris()[0]);

        var type = file.query_file_type(GLib.FileQueryInfoFlags.NONE, null);
        if(type == GLib.FileType.REGULAR) {
            print(file.get_basename());
        } else {
            print(file.get_basename());
        }
    }
}