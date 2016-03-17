(function ($) {

  Drupal.behaviors.nodeFieldsetSummaries = {
    attach: function (context) {
      $('fieldset.unit-type-form-constraints', context).drupalSetSummary(function (context) {
        var vals = [];

        if ($('.form-item-bat-availability-range-unit input', context).is(':checked')) {
          vals.push(Drupal.t('Unit constraints enabled'));
        }
        else {
          vals.push(Drupal.t('Unit constraints disabled'));
        }

        if ($('.form-item-bat-availability-range-type input', context).is(':checked')) {
          vals.push(Drupal.t('Unit type constraints enabled'));
        }
        else {
          vals.push(Drupal.t('Unit type constraints disabled'));
        }

        return vals.join('<br />');
      });

    }
  };

})(jQuery);
