public class ShareView : Gtk.Grid {
    private Gtk.Image new_document;
    private Gtk.Label share_link;
    private Gtk.Label file_name;
    private Gtk.Button clear_button;
    private const Gtk.TargetEntry[] targets = {   {"text/uri-list",0,0}};

    public ShareView() {

            orientation = Gtk.Orientation.VERTICAL;
            margin_bottom = 24;
            halign = valign =  Gtk.Align.CENTER;
            //hexpand = false;
            row_spacing = 12;


            new_document = new Gtk.Image.from_icon_name ("document-new-symbolic", Gtk.IconSize.DIALOG);
            new_document.pixel_size = 128;

            Gtk.drag_dest_set(new_document, Gtk.DestDefaults.ALL, targets, Gdk.DragAction.COPY);

            new_document.drag_data_received.connect(on_drag_drop);

            file_name = new Gtk.Label ("");

            share_link = new Gtk.Label ("Generate sharelink");
            share_link.use_markup = file_name.use_markup = true;
            share_link.ellipsize = file_name.ellipsize = Pango.EllipsizeMode.END;
            share_link.max_width_chars = file_name.max_width_chars = 32;
            share_link.use_underline = true;

            clear_button = new Gtk.Button.with_label ("Clear");
            clear_button.hexpand_set = false;
            clear_button.expand = false;
            clear_button.get_style_context().add_class (Gtk.STYLE_CLASS_DESTRUCTIVE_ACTION);
            clear_button.clicked.connect (clear_link);

            add(new_document);
            add (file_name);
            add (share_link); 
                   
        }

    private void clear_link () {
        new_document.icon_name = "document-new-symbolic";
        file_name.label = "";
        share_link.label = "Generate sharelink";
        clear_button.visible = false;
    }

    private void gen_new_link (string file_uri) {
        string file_absolut_path = file_uri.slice(7,file_uri.length);
        
        string url = Dropbox.gen_share_link(file_absolut_path);
        share_link.label = "<a href=\""+url+"\">"+url.slice(12,url.length)+"</a>";
    }

    private void on_drag_drop (Gtk.Widget widget, Gdk.DragContext context, int x, int y, Gtk.SelectionData data, uint info, uint time) {
        new_document.icon_name = "image-loading-symbolic";
        
        var file = GLib.File.new_for_uri (data.get_uris()[0]);

        file_name.label = "<b>"+file.get_basename ()+"</b>";

        gen_new_link(data.get_uris()[0]);
        new_document.icon_name = "process-completed";
        
        if( this.get_children().length() == 3) {
            this.add (clear_button);
            clear_button.visible = true;
        } else {
            clear_button.visible = true;
        }
        
        //return true;
    }
}